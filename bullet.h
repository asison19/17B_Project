
#ifndef BULLET_H
#define BULLET_H

//bullet.h
/*
 * this is the parent class for the stuff that kills the player character
*/
#include <QObject>
#include <QVector2D>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QDebug>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    QVector2D * velocity;
    float speed;
    QTimer * timer;
    //float damage;
    QPixmap *hitboxPixmap;

    short version;
    int speed1;
    int speed2;

    void versionCheck();

public:
    //explicit Bullet(QObject *parent = 0);
    Bullet();
    ~Bullet();
    bool checkIfOutside();

signals:

public slots:
    virtual void Move();
};

#endif // BULLET_H
