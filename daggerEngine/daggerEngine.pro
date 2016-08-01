TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += debug_and_release

SOURCES += main.cpp \
    window/window.cpp \
    scene/scene.cpp \
    actor/actor.cpp \
    component/clickable.cpp \
    component/movable.cpp \
    timer/timer.cpp \
    utilities/vector2.cpp \
    utilities/collisionDetection.cpp \
    audio/sound_player.cpp


QMAKE_CXXFLAGS += -std=c++11

LIBS += -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

HEADERS += \
    window/window.h \
    actor/actor.h \
    scene/scene.h \
    state/state.h \
    component/component.h \
    component/clickable.h \
    component/movable.h \
    timer/timer.h \
    utilities/vector2.h \
    utilities/collisionDetection.h \
    audio/sound_player.h

