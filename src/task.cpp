#include "task.h"
#include "writerMessagesSkype.h"
#include <QString>
#include <iostream>

TaskSkype::TaskSkype() {
	m_bDebug = false;
};

QString TaskSkype::help() {
	return "\t--debug - viewing debug messages";
};

QString TaskSkype::name() {
	return "Skype";
};

QString TaskSkype::author() {
	return "Igor Polyakov";
};

QString TaskSkype::description() {
	return "Task is search logs of Skype";
};

QString TaskSkype::license() {
	return "MIT License";
};

QString TaskSkype::licenseFull() {
	return "Look here: https://raw.githubusercontent.com/tusur-coex/coex-plugin-task-skype/master/LICENSE";
};

bool TaskSkype::isSupportOS(const coex::ITypeOperationSystem *) {
    return true;
};

bool TaskSkype::init(const coex::IConfig *pConfig){
	m_pConfig = pConfig;
	m_bDebug = pConfig->isDebugEnabled();
	return true;
};

bool TaskSkype::execute() {
	// example usage options
    if (m_bDebug) {
        qDebug() << "===============TaskSkype================\n\n";
        qDebug() << "Debug mode ON\n";
        qDebug() << "InputFolder: " << m_pConfig->inputFolder() << "\n";
    };

    QDir dir(m_pConfig->outputFolder());
    dir.mkdir("skype");

	QString path = m_pConfig->inputFolder();

    writerMessagesSkype skypeAccouts (m_pConfig->outputFolder() + "//skype/accounts.xml");
    writerMessagesSkype skypeMessages (m_pConfig->outputFolder() + "//skype/message.xml");
    writerMessagesSkype skypeContacts (m_pConfig->outputFolder() + "//skype/contacts.xml");
    writerMessagesSkype skypeCalls (m_pConfig->outputFolder() + "//skype/calls.xml");
    if(!skypeMessages.opened()||!skypeContacts.opened()||!skypeAccouts.opened()||!skypeCalls.opened())
    {
        qDebug() << "Failed task :: Can't create output folder & files\n";
        return false;
    }
    QRegExp skypePathLog(".*Skype.*main.db");
    QDirIterator dirPath (path, QDir::Files | QDir::NoSymLinks | QDir::Hidden | QDir::System | QDir::AllEntries, QDirIterator::Subdirectories);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "skype_sqlite_db");

	while(dirPath.hasNext())
	{
		if (dirPath.next().contains(skypePathLog))
		{
			QString qwerty = skypePathLog.cap(0);
            path = dirPath.filePath();
            QFileInfo f(path);
            QString test = f.fileName();
            if(test != "main.db")
                continue;
            if(m_bDebug)
                std::cout << "Found database :: " << qwerty.toStdString() << "\n";

            db.setDatabaseName(path);
            if( !db.open() )
            {
                if(m_bDebug)
                    std::cout << "Not connected!";// << db.lastError() << "\n";
            }
            if(m_bDebug)
                std::cout << "Connected!\n";
            /*QStringList listOfTables;
            listOfTables << "DbMeta" << "Contacts" << "LegacyMessages" <<  "Calls"
                << "Accounts" << "Transfers" << "Voicemails" << "Chats"
                << "Messages" << "ContactGroups" << "Videos" << "SMSes"
                << "CallMembers" << "ChatMembers" << "Alerts" << "Conversations"
                << "Participants" << "VideoMessages";*/
            QString sql = "select skypename, fullName, emails, ipcountry from  Accounts;";
            QSqlQuery query(db);

            if (query.exec(sql) != false) {
                while (query.next())
                {
                    QSqlRecord rec = query.record();
                    account = query.value(rec.indexOf("skypename")).toString();
                    QString fullName = query.value(rec.indexOf("fullName")).toString();
                    QString emails = query.value(rec.indexOf("emails")).toString();
                    QString ipcountry = query.value(rec.indexOf("ipcountry")).toString();
                    skypeAccouts.writeInfo(account,fullName,emails,ipcountry);
                }
            }
            else {
                if(m_bDebug)
                    qDebug() << query.lastError().text();
            }
            sql = "select skypename, fullName, birthday, gender, phone_mobile, languages, country, city from Contacts";
            if (query.exec(sql) != false) {
                while (query.next())
                {
                    QSqlRecord rec = query.record();
                    QString skypename = query.value(rec.indexOf("skypename")).toString();
                    QString fullName = query.value(rec.indexOf("fullName")).toString();
                    QString birthday = query.value(rec.indexOf("birthday")).toString();
                    QString gender = query.value(rec.indexOf("gender")).toString();
                    QString phone_mobile = query.value(rec.indexOf("phone_mobile")).toString();
                    QString languages = query.value(rec.indexOf("languages")).toString();
                    QString country = query.value(rec.indexOf("country")).toString();
                    QString city = query.value(rec.indexOf("city")).toString();
                    skypeContacts.writeContacts(account, skypename,fullName,birthday,gender,phone_mobile,languages,country,city);
                }
            } else {
                if(m_bDebug)
                    qDebug() << query.lastError().text();
            }
            sql = "select author, timestamp, body_xml from Messages;";
            query.exec(sql);
            if (query.exec(sql) != false)
            {
                while (query.next())
                {
                    QSqlRecord rec = query.record();
                    QString author = query.value(rec.indexOf("author")).toString();
                    QString timestamp = query.value(rec.indexOf("timestamp")).toString();
                    //QDateTime::fromTime_t(x);
                    QString body_xml = query.value(rec.indexOf("body_xml")).toString();

                    skypeMessages.writeMessage(author,timestamp,body_xml);
                }
            } else {
                if(m_bDebug)
                    qDebug() << query.lastError().text();
            }
            sql = "select begin_timestamp, duration, host_identity, current_video_audience from Calls;";
            query.exec(sql);
            if (query.exec(sql) != false) {
                while (query.next())
                {
                    QSqlRecord rec = query.record();
                    QString begin_timestamp = query.value(rec.indexOf("begin_timestamp")).toString();
                    QString duration = query.value(rec.indexOf("duration")).toString();
                    QString host_identity = query.value(rec.indexOf("host_identity")).toString();
                    QString current_video_audience = query.value(rec.indexOf("current_video_audience")).toString();
                    skypeCalls.writeCalls(begin_timestamp,duration,host_identity,current_video_audience);
                }
            } else {
                if(m_bDebug)
                    qDebug() << query.lastError().text();
            }
        }
	}
    return true;
}
