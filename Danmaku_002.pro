#-------------------------------------------------
#
# Project created by QtCreator 2016-11-13T13:49:13
#
#-------------------------------------------------

QT       += core gui \
            multimedia

CONFIG += resources_big

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Danmaku_002
TEMPLATE = app


SOURCES += src/main.cpp \
    src/character.cpp \
    src/gamelevel.cpp \
    src/projectile.cpp \
    src/enemy.cpp \
    src/enemy_1.cpp \
    src/bullet.cpp \
    src/bulletmedium.cpp \
    src/characterhitbox.cpp \
    src/enemy_2.cpp \
    src/enemy_boss.cpp \
    src/bulletlarge.cpp

HEADERS  += \
    headers/character.h \
    headers/gamelevel.h \
    headers/projectile.h \
    headers/enemy.h \
    headers/enemy_1.h \
    headers/bullet.h \
    headers/bulletmedium.h \
    headers/characterhitbox.h \
    headers/enemy_2.h \
    headers/enemy_boss.h \
    headers/bulletlarge.h

RESOURCES += \
    resources/resources.qrc
