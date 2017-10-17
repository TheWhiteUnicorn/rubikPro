TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= core gui widgets

SOURCES += main.cpp \
    mainwindow.cpp \
    dialog.cpp \
    welcome.cpp

    INCLUDEPATH += "C:/Program Files/opencv-3.2.0/build/install/include"
    INCLUDEPATH += D:\Qt
    LIBS += -L"C:/Program Files/opencv-3.2.0/build/lib" -lopencv_core320 \
    -lopencv_highgui320 \
    -lopencv_imgproc320 \
    -lopencv_imgcodecs320 \
    -lopencv_video320 \
    -lopencv_videoio320 \
    -lopencv_videostab320

FORMS += \
    mainwindow.ui \
    welcome.ui \
    dialog.ui

HEADERS += \
    mainwindow.h \
    dialog.h \
    welcome.h

DEFINES += QT_DEPRECATED_WARNINGS

QT += widgets

DISTFILES +=

