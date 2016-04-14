TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    window/window.cpp \
    scene/scene.cpp


QMAKE_CXXFLAGS += -std=c++11

LIBS += -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

HEADERS += \
    window/window.h \
    actor/actor.h \
    scene/scene.h

