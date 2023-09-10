QMAKE_POST_LINK += $$quote(cp $$PWD/parliament.db $$OUT_PWD)

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sqlite_qt

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    dbmanager.cpp \
    dialog.cpp \
    expandedcard.cpp \
    main.cpp \
    mainwindow.cpp \
    mp.cpp \
    finances.cpp \
    parties.cpp

HEADERS += \
    card.h \
    dbmanager.h \
    dialog.h \
    expandedcard.h \
    mainwindow.h \
    mp.h \
    finances.h \
    parties.h

FORMS += \
    card.ui \
    dialog.ui \
    expandedcard.ui \
    mainwindow.ui \
    parties.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
