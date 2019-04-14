TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    wind.cpp \
    sgbg.cpp \
    maps.cpp \
    bird.cpp \
    sgtp.cpp
INCLUDEPATH += ../SDL2/include/
LIBS += -L../SDL2/lib/x86 -lSDL2
LIBS += -L../SDL2/lib/x86 -lSDL2main
LIBS += -L../SDL2/lib/x86 -lSDL2test

HEADERS += \
    sgbg.h \
    maps.h \
    bird.h \
    sgtp.h
