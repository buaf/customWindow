#-------------------------------------------------
#
# Project created by QtCreator 2014-05-21T17:58:24
#
#-------------------------------------------------

QT       += core gui
CONFIG += C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CustomWindow
TEMPLATE = app


SOURCES += main.cpp\
    Utils/utils.cpp \
    customwidget.cpp \
    windowcustomframe.cpp

HEADERS  += \
    Utils/utils.h \
    customwidget.h \
    windowcustomframe.h

FORMS    +=

RESOURCES += \
    R.qrc
