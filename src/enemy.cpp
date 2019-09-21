#include "enemy.h"
#include <QDebug>

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

//all enemies use this for damage and health checking
void Enemy::takeDamage(float damage)
{
    hp = hp - damage;
    if(hp<=0)
    {
        scene()->removeItem(this);
        sound->setMedia(QUrl("qrc:/Sounds/Absorb1.wav"));
        playSound(sound);
        delete this;
        return;
    }
}

//sound for dying and shooting, depending on which is passed in
void Enemy::playSound(QMediaPlayer *sound)
{
    if(sound->state() == QMediaPlayer::PlayingState)
    {
        sound->setPosition(0);
    }
    else if(sound->state() == QMediaPlayer::StoppedState)
    {
        sound->play();
    }
}

//checks if the enemy is out of bounds
void Enemy::checkIfOutOfBounds()
{
    if(y() > 850 || x() > 650 || x() < 0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
}

void Enemy::Move()
{
    qDebug() << "enemy_move";
    setPos(x()+velocity->x(), y()+velocity->y());
    if(y() > 900)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
}

void Enemy::Shoot()
{
    qDebug() << "Enemy_shoot";
}
