#ifndef CHARACTERHITBOX_H
#define CHARACTERHITBOX_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>

#include "bulletmedium.h"
#include "bulletlarge.h"
#include "enemy_1.h"
#include "enemy_2.h"
#include "enemy_boss.h"

class CharacterHitbox : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CharacterHitbox();
    ~CharacterHitbox();
    bool CollisionCheck();

signals:

public slots:
    //void follow();
};

#endif // CHARACTERHITBOX_H

