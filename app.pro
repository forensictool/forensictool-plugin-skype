include(version.pri)

TEMPLATE = app
TARGET = coex-skype
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui
QT += sql
CONFIG += dll

INCLUDEPATH += src/coex/v0.2.2/interfaces/

SOURCES += \
	src/app.cpp \
	src/task.cpp \
	src/writerMessagesSkype.cpp \
	src/coex/v0.2.2/helpers/config.cpp \
	src/coex/v0.2.2/helpers/typeos.cpp \


HEADERS += \
	src/task.h \
	src/writerMessagesSkype.h \
	src/coex/v0.2.2/helpers/config.h \
	src/coex/v0.2.2/helpers/typeos.h \
	


