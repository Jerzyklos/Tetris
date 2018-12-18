TEMPLATE = app
TARGET = Tetris

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += console
SOURCES += \
    main.cpp \
    window.cpp \
    game.cpp \
    board.cpp \
    shapes.cpp \
    rect.cpp \
    shapefactory.cpp

HEADERS += \
    window.h \
    game.h \
    board.h \
    shapes.h \
    rect.h \
    shapefactory.h

DISTFILES += \
    komentarze
