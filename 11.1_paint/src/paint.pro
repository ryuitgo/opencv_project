TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

linux {
    message(==== linux ====)
    INCLUDEPATH += /home/ryuitgo/dev/3rd/opencv/opencv-4.0.0/include/opencv4
    LIBS += -L/home/ryuitgo/dev/3rd/opencv/opencv-4.0.0/lib -lopencv_core
}

SOURCES += main.cpp \
    layout.cpp

HEADERS += \
    layout.h
