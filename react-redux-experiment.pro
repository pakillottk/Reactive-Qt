#-------------------------------------------------
#
# Project created by QtCreator 2016-12-02T20:18:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = react-redux-experiment
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    store.cpp \
    reducer.cpp \
    action.cpp \
    storesuscriber.cpp \
    todosreducer.cpp \
    todosactions.cpp

HEADERS  += mainwindow.h \
    store.h \
    reducer.h \
    action.h \
    storesuscriber.h \
    todosreducer.h \
    todosactions.h

FORMS    += mainwindow.ui
