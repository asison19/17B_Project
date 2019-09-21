#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QVector2D>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include <QMediaPlayer>
#include <QUrl>

/*
#include "projectile.h"

class Projectile;
*/

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    QVector2D * velocity;
    QTimer * timer;
    QMediaPlayer *sound;

public:
    float hp;
    int imageOffsetWidth;
    int imageOffsetHeight;

    Enemy();
    ~Enemy();
    void takeDamage(float damage);
    void playSound(QMediaPlayer *sound);
    void checkIfOutOfBounds();

signals:

public slots:
    virtual void Move();
    virtual void Shoot();
};

#endif // ENEMY_H
