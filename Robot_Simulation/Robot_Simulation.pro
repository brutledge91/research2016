#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T23:09:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Robot_Simulation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphic_engine.cpp \
    utilities.cpp \
    myrobot1.cpp \
    dynamic_obstacle.cpp \
    detected_obstacle.cpp

HEADERS  += mainwindow.h \
    graphic_engine.h \
    constants.h \
    utilities.h \
    myrobot1.h \
    dynamic_obstacle.h \
    detected_obstacle.h

FORMS    += mainwindow.ui
