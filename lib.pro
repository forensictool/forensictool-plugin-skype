include(version.pri)

TEMPLATE = lib
TARGET = forensictool-plugin-skype
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui
QT += sql
CONFIG += dll

INCLUDEPATH += src/forensictool-core/v0.3.1/interfaces/

SOURCES += \
	src/lib.cpp \
	src/task.cpp \
	src/writerMessagesSkype.cpp \


HEADERS += \
	src/task.h \
	src/writerMessagesSkype.h \
