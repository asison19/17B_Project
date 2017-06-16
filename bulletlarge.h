#ifndef BULLETLARGE_H
#define BULLETLARGE_H

#include "bullet.h"

class BulletLarge : public Bullet
{
private:

public:
    BulletLarge(short version);

public slots:
    void Move();
};

#endif // BULLETLARGE_H
