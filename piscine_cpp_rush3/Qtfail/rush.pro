#-------------------------------------------------
#
# Project created by QtCreator 2014-01-26T01:24:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rush
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ADisplay.cpp \
    CPUInfo.cpp \
    RAMInfo.cpp \
    UserInfo.cpp \
    OSkernel.cpp \
    DateHour.cpp \
    Monitor.cpp \
    CPUInfoDisplay.cpp \
    DateHourDisplay.cpp \
    RAMInfoDisplay.cpp \
    UserInfoDisplay.cpp \
    misc.cpp \
    curses.cpp \
    OSKernelDisplay.cpp

HEADERS  += mainwindow.h \
    ADisplay.hpp \
    CPUInfo.hpp \
    RAMInfo.hpp \
    UserInfo.hpp \
    DateHour.hpp \
    CPUInfoDisplay.hpp \
    DateHourDisplay.hpp \
    IModuleDisplay.hpp \
    OSKernelDisplay.hpp \
    RAMInfoDisplay.hpp \
    UserInfoDisplay.hpp \
    AModule.hpp \
    OSKernel.hpp \
    Monitor.hpp \
    curses.hpp \
    misc.hpp \
    IMonitorModule.hpp

FORMS    += mainwindow.ui
