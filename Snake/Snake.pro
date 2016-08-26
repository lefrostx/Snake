#-------------------------------------------------
#
# Project created by QtCreator 2016-08-26T15:46:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app

CONFIG += c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    box.cpp \
    gamemap.cpp \
    gamemain.cpp \
    drawer.cpp \
    snake.cpp

HEADERS  += mainwindow.h \
    box.h \
    cell.h \
    mathematic.h \
    gamemap.h \
    gamemain.h \
    drawer.h \
    snake.h \
    coord.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
