#-------------------------------------------------
#
# Project created by QtCreator 2016-09-27T14:53:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fixing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sales.cpp \
    purchase.cpp \
    member.cpp \
    fileparsing.cpp \
    userwindow.cpp

HEADERS  += mainwindow.h \
    header.h \
    purchase.h \
    sales.h \
    member.h \
    fileparsing.h \
    userwindow.h

FORMS    += mainwindow.ui \
	userwindow.ui

DISTFILES += \
    members.txt \
    purchases.txt \
	myresources.qrc
