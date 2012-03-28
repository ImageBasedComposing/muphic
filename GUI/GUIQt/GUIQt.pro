#-------------------------------------------------
#
# Project created by QtCreator 2011-10-20T11:57:20
#
#-------------------------------------------------

QT       += core gui
QT += network xml webkit phonon

TARGET = GUIQt
TEMPLATE = app


SOURCES += main.cpp\
        guimupic.cpp \
    ../../Muphic/common/src/launcher.cpp \
    Pincel.cpp \
    Escena.cpp \
    ../../Muphic/common/src/Vertice.cpp \
    ../../Muphic/common/src/Figuras.cpp \
    ../../Muphic/common/src/Figura.cpp \
    ../../Muphic/TinyXML/src/tinyxmlparser.cpp \
    ../../Muphic/TinyXML/src/tinyxmlerror.cpp \
    ../../Muphic/TinyXML/src/tinyxml.cpp \
    ../../Muphic/TinyXML/src/tinystr.cpp \
    polygonwidget.cpp \
    ../../Muphic/common/src/UsrConf.cpp \
    seekbar.cpp \
    volumebar.cpp

HEADERS  += guimupic.h \
    ../../Muphic/common/include/launcher.h \
    Pincel.h \
    Escena.h \
    ../../Muphic/common/include/Vertice.h \
    ../../Muphic/common/include/math_functions.h \
    ../../Muphic/common/include/Figuras.h \
    ../../Muphic/common/include/Figura.h \
    ../../Muphic/common/include/aux_functions.h \
    ../../Muphic/TinyXML/include/tinyxml.h \
    ../../Muphic/TinyXML/include/tinystr.h \
    ../../Muphic/TinyXML/include/tinyxml.h \
    polygonwidget.h \
    ../../Muphic/common/include/UsrConf.h \
    seekbar.h \
    volumebar.h

FORMS    += guimupic.ui

INCLUDEPATH += ../../Muphic/common/include
INCLUDEPATH += ../../Muphic/TinyXML/include
DEFINES += __LINUX=1

 wince*{
 DEPLOYMENT_PLUGIN += phonon_ds9 phonon_waveout
 }









