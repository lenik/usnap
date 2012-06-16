#-------------------------------------------------
#
# Project created by QtCreator 2012-06-16T11:05:02
#
#-------------------------------------------------

TARGET = libqtlenik
TEMPLATE = lib
CONFIG += staticlib

SOURCES += libqtlenik.cpp

HEADERS += libqtlenik.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog
