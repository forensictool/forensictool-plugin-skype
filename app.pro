#.pro file
#Application version
VERSION_MAJOR = 0
VERSION_MINOR = 1
VERSION_BUILD = 0

DEFINES += "VERSION_MAJOR=$$VERSION_MAJOR"\
       "VERSION_MINOR=$$VERSION_MINOR"\
       "VERSION_BUILD=$$VERSION_BUILD"

VERSION = $${VERSION_MAJOR}.$${VERSION_MINOR}.$${VERSION_BUILD}


TEMPLATE = app
TARGET = coex-skype-win
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui
QT += sql
CONFIG += dll
SOURCES += \
	src/skypeWinTask.cpp\
	src/writerMessagesSkype.cpp


HEADERS += \
	src/coex.h \
	src/task.h
	src/skypeWinTask.h\
	src/writerMessagesSkype.h


