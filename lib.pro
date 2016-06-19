include(version.pri)

TEMPLATE = lib
TARGET = coex-plugin-task-skype
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui
QT += sql
CONFIG += dll

INCLUDEPATH += src/coex/v0.2.2/interfaces/

SOURCES += \
	src/lib.cpp \
	src/task.cpp \
	src/writerMessagesSkype.cpp \


HEADERS += \
	src/coex.h \
	src/task.h \
	src/writerMessagesSkype.h \
