QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = HEAVEN VS HELL
TEMPLATE = app


CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainstruct.cpp \
    mainwindow.cpp \
    smtp.cpp \
    struct_arbolfamilias.cpp \
    struct_cielo.cpp \
    struct_file.cpp \
    struct_infierno.cpp \
    struct_mundo.cpp \
    struct_personas.cpp

HEADERS += \
    mainstruct.h \
    mainwindow.h \
    smtp.h \
    struct_arbolfamilias.h \
    struct_cielo.h \
    struct_file.h \
    struct_infierno.h \
    struct_mundo.h \
    struct_personas.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    MyResources.qrc
