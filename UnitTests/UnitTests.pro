TEMPLATE = app
TARGET = UnitTests

QT       += core gui sql

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
#CONFIG -= qt

INCLUDEPATH += \
    ../qtGuiApplication

SOURCES += \
        main.cpp \
        ../qtGuiApplication/dbmanager.cpp \
        ../qtGuiApplication/finances.cpp \
        ../qtGuiApplication/mp.cpp

HEADERS += \
        ../qtGuiApplication/dbmanager.h \
        ../qtGuiApplication/finances.h \
        ../qtGuiApplication/mp.h


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
