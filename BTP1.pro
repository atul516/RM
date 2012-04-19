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
    mainwindow.cpp \
    drawhole.cpp \
    hole.cpp \
    surface.cpp \
    GLContour.cpp \
    Contour.cpp
HEADERS += GLWidget.h \
    imageloader.h \
    parseCSV.h \
    params.h \
    mainwindow.h \
    drawhole.h \
    hole.h \
    surface.h \
    GLContour.h \
    Contour.h
FORMS += \ 
    mainwindow.ui
