#ifndef PROJECTILE_H
#define PROJECTILE_H

//Projectile.h
/*
 * This is the Player's bullets
*/
#include <QObject>
#include <QVector2D>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QDebug>

#include "enemy_1.h"
#include "enemy_2.h"
#include "enemy_boss.h"

class Projectile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QVector2D * velocity;
    float speed;
    QTimer * timer;
    //QList<QGraphicsItem*> colliding_Items = collidingItems();
    float damage;
public:
    Projectile();
    ~Projectile();

signals:

public slots:
    void Move();
};

#endif // PROJECTILE_H
