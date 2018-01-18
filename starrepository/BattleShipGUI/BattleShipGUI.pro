#-------------------------------------------------
#
# Project created by QtCreator 2017-11-05T23:00:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BattleShipGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ../BattleScrabble/CrossMissile.cpp \
    ../BattleScrabble/Missile.cpp \
    ../BattleScrabble/Ping.cpp \
    ../BattleScrabble/Player.cpp \
    ../BattleScrabble/Point.cpp \
    ../BattleScrabble/Ship.cpp \
    boardrender.cpp \
    shiprender.cpp \
    ../BattleScrabble/BattleshipBoard.cpp \
    ../BattleScrabble/ScrabbleBoard.cpp \
    ../BattleScrabble/ScrabbleTileContainer.cpp \
    playerrender.cpp \
    gamerender.cpp \
    ../BattleScrabble/Game.cpp \
    difficultywindow.cpp \
    ../BattleScrabble/HumanPlayer.cpp
    difficultywindow.cpp
    ../BattleScrabble/HumanPlayer.cpp \

HEADERS += \
        mainwindow.h \
    ../BattleScrabble/AI.h \
    ../BattleScrabble/Ammo.h \
    ../BattleScrabble/CrossMissile.h \
    ../BattleScrabble/HumanPlayer.h \
    ../BattleScrabble/Missile.h \
    ../BattleScrabble/Ping.h \
    ../BattleScrabble/Player.h \
    ../BattleScrabble/Point.h \
    ../BattleScrabble/Ship.h \
    boardrender.h \
    shiprender.h \
    ../BattleScrabble/BattleshipBoard.h \
    ../BattleScrabble/ScrabbleBoard.h \
    ../BattleScrabble/ScrabbleTile.h \
    ../BattleScrabble/ScrabbleTileContainer.h \
    playerrender.h \
    difficultywindow.h \
    ../BattleScrabble/Game.h
    ../BattleScrabble/Game.h
    gamerender.h \

FORMS += \
        mainwindow.ui \
    difficultywindow.ui

RESOURCES += \
    bsresource.qrc
