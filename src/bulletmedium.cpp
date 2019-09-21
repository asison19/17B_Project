#include "bulletmedium.h"

BulletMedium::BulletMedium(short version)
{
    this->setPixmap(QPixmap(":/Images/bulletMediumRed.png"));
    //velocity = new QVector2D(1,1);  //(1,1) makes it move in a wave like pattern / like so and moves downward
    this->version = version;

    speed1 = 6;
    speed2 = 4;

    versionCheck();
    //hitboxPixmap = new QPixmap;
    //hitboxPixmap->setMask(hitboxPixmap->createHeuristicMask());
    //this->opaqueArea();

    timer = new QTimer(this);
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(Move()));
    timer->start(30);

    //setTransformOriginPoint(this->pixmap().width()/2, this->pixmap().height()/2);

}

void BulletMedium::Move()
{
    this->setPos(x() + velocity->x(), y() + velocity->y());
    //velocity->setX(velocity->x()+ 0.1);    //numbers larger than one are hella fast

    if(checkIfOutside())
    {
        scene()->removeItem(this);
        delete this;

    }
}
