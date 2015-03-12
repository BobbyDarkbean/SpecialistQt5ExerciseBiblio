#-------------------------------------------------
#
# Project created by QtCreator 2015-03-02T20:01:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = biblio
TEMPLATE = app

TRANSLATIONS += biblio_rus.ts biblio_ger.ts


SOURCES += \
    application.cpp \
    bibliomodel.cpp \
    edit.cpp \
    helpers.cpp \
    itemeditdialog.cpp \
    itemeditframe.cpp \
    main.cpp\
    mainwindow.cpp \
    table.cpp

HEADERS += \
    application.h \
    bibliomodel.h \
    data.h \
    edit.h \
    helpers.h \
    itemeditdialog.h \
    itemeditframe.h \
    items.h \
    mainwindow.h \
    table.h

RESOURCES += \
    biblio.qrc
