#-------------------------------------------------
#
# Project created by QtCreator 2016-11-23T20:10:16
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimCGenerator
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    generator.cpp \
    lookup.cpp \
    gearselection.cpp \
    databasehandler.cpp

HEADERS  += dialog.h \
    generator.h \
    innards.h \
    lookup.h \
    gearselection.h \
    databasehandler.h

FORMS    += dialog.ui \
    gearselection.ui

DISTFILES += \
    TODO

copydata.commands = $(COPY_DIR) $$PWD/simcgendb.db $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)

QMAKE_EXTRA_TARGETS += first copydata
