#ifndef __FORENSICTOOL_TASK_SKYPE_H__
#define __FORENSICTOOL_TASK_SKYPE_H__

#include "forensictool.h"

#include <QDebug>
#include <QDateTime>
#include <QDirIterator>
#include <QFile>
#include <QRegExp>
#include <QSqlDatabase>
#include <QString>
#include <QTextStream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class TaskSkype : forensictool::ITask
{
	public:
		TaskSkype();
		virtual QString help();
		virtual QString name();
		virtual QStringList authors();
		virtual QString description();
		virtual QString license();
		virtual QString licenseFull();

		virtual bool isSupportOS(const forensictool::ITypeOperationSystem *os);
		virtual bool init(const forensictool::IConfig *config);
		virtual bool execute();
	private:
		bool m_bDebug;
        QString account;
        const forensictool::IConfig *m_pConfig;
};

extern "C"
{
	forensictool::ITask* createTask();
}

#endif // __FORENSICTOOL_TASK_SKYPE_H__
