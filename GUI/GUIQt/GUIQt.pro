#-------------------------------------------------
#
# Project created by QtCreator 2011-10-20T11:57:20
#
#-------------------------------------------------

QT       += core gui

TARGET = GUIQt
TEMPLATE = app


SOURCES += main.cpp\
        guimupic.cpp \
    ../../Muphic/common/src/launcher.cpp

HEADERS  += guimupic.h \
    ../../Muphic/common/include/launcher.h

FORMS    += guimupic.ui

INCLUDEPATH += ../../Muphic/common/include
DEFINES += __LINUX=1
