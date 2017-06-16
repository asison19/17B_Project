#ifndef ENEMY_BOSS_H
#define ENEMY_BOSS_H

#include "enemy.h"
#include "bulletmedium.h"
#include "bulletlarge.h"

class Enemy_Boss : public Enemy
{
private:
    QTimer * bulletTimer;
    QTimer * bigBulletTimer;
    int sceneWidth;
    int sceneHeight;

    int amount = 0;
    int turnAmount = 50;

public:
    Enemy_Boss(int sWidth, int sHeight);

public slots:
    void Move();
    void Shoot();
};

#endif // ENEMY_BOSS_H
