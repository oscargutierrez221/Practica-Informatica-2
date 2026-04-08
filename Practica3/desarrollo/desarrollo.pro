TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        compresion_laz78.cpp \
        compresion_rle.cpp \
        encriptar.cpp \
        main.cpp

HEADERS += \
    compresion_laz78.h \
    compresion_rle.h \
    encriptar.h
