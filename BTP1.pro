# -------------------------------------------------
# Project created by QtCreator 2011-08-24T19:58:20
# -------------------------------------------------
QT += opengl \
    xml \
    xmlpatterns
QT += mobility multimediakit
CONFIG += mobility
MOBILITY = multimedia
TARGET = BTP1
TEMPLATE = app
SOURCES += main.cpp \
    GLWidget.cpp \
    imageloader.cpp \
    drillhole.cpp \
    mainwindow.cpp
HEADERS += GLWidget.h \
    imageloader.h \
    parseCSV.h \
    drillhole.h \
    params.h \
    mainwindow.h
FORMS += \ 
    mainwindow.ui


