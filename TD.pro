QT += core
QT -= gui

CONFIG += c++11

TARGET = TD
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    play.cpp \
    envirenment.cpp \
    error_msg.cpp \
    landscape.cpp \
    shape.cpp

HEADERS += \
    envirenment.h \
    error_msg.h \
    landscape.h \
    shape.h
