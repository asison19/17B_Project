/*
 * main.cpp
 */

#include <QApplication>

#include "gamelevel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameLevel g;

    return a.exec();
}
