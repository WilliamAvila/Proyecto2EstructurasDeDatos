#-------------------------------------------------
#
# Project created by QtCreator 2014-02-24T15:38:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mylabel.cpp \
    useradmin.cpp \
    windowuser.cpp \
    TinyXml/tinystr.cpp \
    TinyXml/tinyxml.cpp \
    TinyXml/tinyxmlerror.cpp \
    TinyXml/tinyxmlparser.cpp \
    dialogerror.cpp \
    dialogsucces.cpp \
    loginadmin.cpp \
    adminmenu.cpp \
    grafo.cpp \
    airport.cpp \
    connection.cpp \
    createconnection.cpp \
    deleteairport.cpp \
    deleteconnection.cpp \
    dijkstra.cpp

HEADERS  += mainwindow.h \
    mylabel.h \
    useradmin.h \
    windowuser.h \
    TinyXml/tinystr.h \
    TinyXml/tinyxml.h \
    dialogerror.h \
    dialogsucces.h \
    loginadmin.h \
    adminmenu.h \
    grafo.h \
    airport.h \
    connection.h \
    createconnection.h \
    deleteairport.h \
    deleteconnection.h \
    dijkstra.h

FORMS    += mainwindow.ui \
    useradmin.ui \
    windowuser.ui \
    dialogerror.ui \
    dialogsucces.ui \
    loginadmin.ui \
    adminmenu.ui \
    createconnection.ui \
    deleteairport.ui \
    deleteconnection.ui

RESOURCES += \
    Resources.qrc
