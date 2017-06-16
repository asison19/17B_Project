#include "bullet.h"

Bullet::Bullet()
{
    //this->setPixmap(QPixmap(":/Images/bulletMediumRed.png"));
    //version = 0;
}

Bullet::~Bullet()
{

}

void Bullet::Move()
{
    qDebug()<<"Bullet move";
}

bool Bullet::checkIfOutside()
{
    //this checks if the projectile is offscreen, and deletes it
    if(y() <= -50 || y() >= 900 || x()>= 650 || x() <=-50)
    {
        //qDebug() << "deleted";
        return true;
    }
    else
    {
        return false;
    }
}

//checks bullets version and gives it the proper velocity
void Bullet::versionCheck()
{
    switch (version)
    {
    case 0:
        velocity = new QVector2D(speed1,0); //east
        break;
    case 1:
        velocity = new QVector2D(speed2,speed2); //south east
        break;
    case 2:
        velocity = new QVector2D(0,speed1); //south
        break;
    case 3:
        velocity = new QVector2D(-speed2,speed2); //south west
        break;
    case 4:
        velocity = new QVector2D(-speed1,0); //west
        break;
    case 5:
        velocity = new QVector2D(-speed2,-speed2); //north west
        break;
    case 6:
        velocity = new QVector2D(0,-speed1); //north
        break;
    case 7:
        velocity = new QVector2D(speed2,-speed2); //north east
        break;

    default:
        velocity = new QVector2D(50,50); //hella far
        break;
    }
}

