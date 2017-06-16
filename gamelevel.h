#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QTimer>

#include "character.h"
#include "enemy_1.h"
#include "enemy_2.h"
#include "enemy_boss.h"

class GameLevel : public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    Character *player;
    QTimer * timer;

    QMediaPlayer *song;

    QTimer * waveTimer;
    int height = 800;
    int width = 600;

    int amount; //for the amount of times a wave should spawn enemies

    int timePassed = 0;

    void wave1();
    void wave2();
    void wave3();
    void wave4();
    void wave5();
    void wave6();
    void bossWave();

public:
    explicit GameLevel(QObject *parent = 0);
    ~GameLevel();

signals:

public slots:
    //this is the entire game's timer to check the second at which the player is at
    void checkTimer();

    void spawnEnemy_1();
    void spawnEnemy_1_twice();
    void spawnEnemy_2_twice();
};

#endif // GAMELEVEL_H
