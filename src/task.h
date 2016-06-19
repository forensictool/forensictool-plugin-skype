#ifndef __COEX_TASK_SKYPE_H__
#define __COEX_TASK_SKYPE_H__

#include "coex.h"

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

class TaskSkype : coex::ITask
{
	public:
		TaskSkype();
		virtual QString help();
		virtual QString name();
		virtual QString author();
		virtual QString description();
		virtual QString license();
		virtual QString licenseFull();

		virtual bool isSupportOS(const coex::ITypeOperationSystem *os);
		virtual bool init(const coex::IConfig *config);
		virtual bool execute();
	private:
		bool m_bDebug;
        QString account;
        const coex::IConfig *m_pConfig;
};

extern "C"
{
	coex::ITask* createTask();
}

#endif // __COEX_TASK_SKYPE_H__
