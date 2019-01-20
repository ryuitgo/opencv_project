TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

linux {
    message(==== linux ====)
    INCLUDEPATH += /home/ryuitgo/dev/3rd/opencv/opencv-4.0.0/include/opencv4
    LIBS += -L/home/ryuitgo/dev/3rd/opencv/opencv-4.0.0/lib -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui
}

SOURCES += main.cpp

HEADERS += \
    menu.hpp \
    icon_flag.hpp
