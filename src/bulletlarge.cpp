#include "bulletlarge.h"

BulletLarge::BulletLarge(short version)
{
    //gives the large bullet a large image
    this->setPixmap(QPixmap(":/Images/bulletLargeRed.png"));

    //version number used for its velocity check
    this->version = version;
    speed1 = 6;
    speed2 = 4;
    versionCheck();

    //timer for its movement
    timer = new QTimer(this);
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(Move()));
    timer->start(30);
}

//moves the bullet
void BulletLarge::Move()
{
    this->setPos(x() + velocity->x(), y() + velocity->y());
    //velocity->setX(velocity->x()+ 0.1);    //numbers larger than one are hella fast

    if(checkIfOutside())
    {
        scene()->removeItem(this);
        delete this;

    }
}
