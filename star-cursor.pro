TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    window.cpp \
    game.cpp \
    cursor.cpp \
    star_point.cpp

HEADERS += \
    window.h \
    game.h \
    cursor.h \
    star_point.h

unix|win32: LIBS += -L$$PWD/../../Qt/5.10.1/i686-w64-mingw32/lib/ -lSDL2
unix|win32: LIBS += -L$$PWD/../../Qt/5.10.1/i686-w64-mingw32/lib/ -lSDL2_image
unix|win32: LIBS += -L$$PWD/../../Qt/5.10.1/i686-w64-mingw32/lib/ -lSDL2_ttf
unix|win32: LIBS += -L$$PWD/../../Qt/5.10.1/i686-w64-mingw32/lib/ -lSDL2_mixer

INCLUDEPATH += $$PWD/../../Qt/5.10.1/i686-w64-mingw32/include
DEPENDPATH += $$PWD/../../Qt/5.10.1/i686-w64-mingw32/include
