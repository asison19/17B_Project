#ifndef ENEMY_1_H
#define ENEMY_1_H

#include <QObject>
#include <QDebug>

#include "enemy.h"
#include "bulletmedium.h"

//class BulletMedium;

class Enemy_1 : public Enemy
{
protected:

private:
    //QVector2D * velocity;
    //QTimer * timer;
    QTimer * bulletTimer;

public:
    Enemy_1();

public slots:
    void Move();
    void Shoot();
};

#endif // ENEMY_1_H

