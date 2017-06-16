#include "gamelevel.h"

/* Game Name:   Boxes In Space
 *
 * This is the scene for the game that the player can see.
 *
 * Note to Self:
 *  unfortunately with too many bullets the game starts to lag.
 *
 */

GameLevel::GameLevel(QObject *parent) : QObject(parent)
{ 
    scene = new QGraphicsScene();
    player = new Character(width, height);
    scene->addItem(player);
    player->setStartingPosition();//putting character in the middle
    player->setFocus();
    player->grabKeyboard();

    //creates the scene
    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    //sets the width and height
    view->setFixedSize(width, height);
    view->setSceneRect(0, 0, width, height);
    view->setBackgroundBrush(QBrush(QImage(":/Images/space.jpg")));

    //this is the timer that controls the other timers and the pace of the game
    waveTimer = new QTimer();
    connect(waveTimer,
            SIGNAL(timeout()),
            this,
            SLOT(checkTimer()));
    waveTimer->start(1000);

    //music for the background
    //song by LukHash
    song = new QMediaPlayer();
    song->setMedia(QUrl("qrc:/Sounds/12 - FAILURE.mp3"));
    if(song->state() == QMediaPlayer::PlayingState)
    {
        song->setPosition(0);
    }
    else if(song->state() == QMediaPlayer::StoppedState)
    {
        song->play();
    }
}

GameLevel::~GameLevel()
{

}

//first wave of enemies
void GameLevel::wave1()
{
    qDebug() << "wave1";
    timer = new QTimer();
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(spawnEnemy_1()));
    timer->start(2500);
}

//second wave of enemies
void GameLevel::wave2()
{
    qDebug() << "wave2";
    timer = new QTimer();
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(spawnEnemy_1_twice()));
    timer->start(2500);
}

//third wave of enemies
void GameLevel::wave3()
{
    qDebug() << "wave3";
    timer = new QTimer();
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(spawnEnemy_2_twice()));
    timer->start(2500);
}

//fourth wave of enemies
void GameLevel::wave4()
{
    qDebug() << "wave4";
    timer = new QTimer();
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(spawnEnemy_1()));
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(spawnEnemy_1_twice()));
    timer->start(2500);
}

//fifth wave of enemies
void GameLevel::wave5()
{
    qDebug() << "wave5";
    timer = new QTimer();
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(spawnEnemy_1_twice()));
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(spawnEnemy_2_twice()));
    timer->start(4000);
}

//sixth wave of enemies
void GameLevel::wave6()
{
    qDebug() << "wave6";
    timer = new QTimer();
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(spawnEnemy_1_twice()));
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(spawnEnemy_2_twice()));
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(spawnEnemy_1()));
    timer->start(5000);
}

//the boss' spawn
void GameLevel::bossWave()
{
    qDebug() << "spawn boss";
    Enemy_Boss * enemy_Boss = new Enemy_Boss(width, height);
    enemy_Boss->setPos((width/2) - enemy_Boss->imageOffsetWidth/2, - enemy_Boss->imageOffsetHeight);
    scene->addItem(enemy_Boss);
}

//this is the timer for the pace of the entire game, and it sets the waves in motion
void GameLevel::checkTimer()
{
    //timer = new QTimer();
    if(timePassed == 0)
    {
        wave1();
    }
    else if(timePassed == 9)    //9 to go with the music
    {
        timer->stop();
        wave2();
    }
    else if(timePassed == 20)
    {
        timer->stop();
        wave3();
    }
    else if(timePassed == 30)
    {
        timer->stop();
        wave4();
    }
    else if(timePassed == 40)
    {
        timer->stop();
        wave5();
    }
    else if(timePassed == 50)
    {
        timer->stop();
        wave6();
    }
    else if(timePassed == 60)
    {
        timer->stop();
    }
    else if(timePassed == 65)
    {
        bossWave();
    }
    else if( timePassed == 75)
    {
        timePassed = 0;
    }
    else if (timePassed == 6000)
    {
        qDebug() << "stop";
        timer->stop();
    }
    ++timePassed;

    //checks if the song is playing and if not, starts it again
    if(song->state() == QMediaPlayer::StoppedState)
    {
           song->play();
    }
}

//spawns enemy 1 from the middle top
void GameLevel::spawnEnemy_1()
{
    qDebug() << "spawn";
    Enemy_1 * enemy_1 = new Enemy_1();
    enemy_1->setPos((width/2) - enemy_1->imageOffsetWidth/2, - enemy_1->imageOffsetHeight);
    scene->addItem(enemy_1);
}

//spawn enemy 1 twice from the top at a quarter there and three quarters there
void GameLevel::spawnEnemy_1_twice()
{
     qDebug() << "spawn2";
     Enemy_1 * enemy_1_1 = new Enemy_1();
     Enemy_1 * enemy_1_2 = new Enemy_1();
     enemy_1_1->setPos((width/4) - enemy_1_1->imageOffsetWidth/2, - enemy_1_1->imageOffsetHeight);
     scene->addItem(enemy_1_1);
     enemy_1_2->setPos((3* width/4) - enemy_1_2->imageOffsetWidth/2, - enemy_1_2->imageOffsetHeight);
     scene->addItem(enemy_1_2);
}

//spawn enemy 2 twice, from the top at a quarter there and three quarters there
void GameLevel::spawnEnemy_2_twice()
{
    qDebug() << "spawn3";
    Enemy_2 * enemy_1_1 = new Enemy_2(0);
    Enemy_2 * enemy_1_2 = new Enemy_2(1);
    enemy_1_1->setPos((width/4) - enemy_1_1->imageOffsetWidth/2, - enemy_1_1->imageOffsetHeight);
    scene->addItem(enemy_1_1);
    enemy_1_2->setPos((3* width/4) - enemy_1_2->imageOffsetWidth/2, - enemy_1_2->imageOffsetHeight);
    scene->addItem(enemy_1_2);
}
