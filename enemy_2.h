#ifndef ENEMY_2_H
#define ENEMY_2_H

#include "enemy.h"
#include "bulletmedium.h"

class Enemy_2  : public Enemy
{
private:
    QTimer * bulletTimer;
    int version;
public:
    Enemy_2(int version);

public slots:
    void Move();
    void Shoot();
};

#endif // ENEMY_2_H
