#ifndef BULLETMEDIUM_H
#define BULLETMEDIUM_H

#include "bullet.h"

class BulletMedium: public Bullet
{
private:

public:
    BulletMedium(short version);
public slots:
    void Move();
};

#endif // BULLETMEDIUM_H
