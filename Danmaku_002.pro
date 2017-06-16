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


SOURCES += main.cpp \
    character.cpp \
    gamelevel.cpp \
    projectile.cpp \
    enemy.cpp \
    enemy_1.cpp \
    bullet.cpp \
    bulletmedium.cpp \
    characterhitbox.cpp \
    enemy_2.cpp \
    enemy_boss.cpp \
    bulletlarge.cpp

HEADERS  += \
    character.h \
    gamelevel.h \
    projectile.h \
    enemy.h \
    enemy_1.h \
    bullet.h \
    bulletmedium.h \
    characterhitbox.h \
    enemy_2.h \
    enemy_boss.h \
    bulletlarge.h

RESOURCES += \
    resources.qrc
