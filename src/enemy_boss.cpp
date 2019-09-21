#include "enemy_boss.h"

Enemy_Boss::Enemy_Boss(int sWidth, int sHeight)
{

    this->sceneWidth = sWidth;
    this->sceneHeight = sHeight;
    this->setPixmap(QPixmap(":/Images/enemy_2_Image - Copy.png"));
    imageOffsetWidth = 50;
    imageOffsetHeight = 50;
    velocity = new QVector2D(0 , 2);

    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/Sounds/Buzzer1.wav"));

    this->hp = 300;

    timer = new QTimer(this);
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(Move()));
    timer->start(30);

    bulletTimer = new QTimer(this);
    connect(bulletTimer,
            SIGNAL(timeout()),
            this,
            SLOT(Shoot()));
    bulletTimer->start(200);

}

//boss' move functoin
void Enemy_Boss::Move()
{
    if(y() < 100)
        setPos(x(), y() + velocity->y());
    else if(turnAmount % 200 < 100 && y() >= 100)   //this is to make it go left
    {
        velocity->setX(-2);
        setPos(x() + velocity->x(), y());
        ++turnAmount;
    }
    else if(turnAmount % 200 >= 100 && y() >= 100)  //this is to make it go right
    {
        velocity->setX(2);
        setPos(x() + velocity->x(), y());
        ++turnAmount;
    }
}

void Enemy_Boss::Shoot()
{
    //boss shoots three medium bullets, then one big bullet, and the pauses for a bit
    if(amount < 3)  //this is the three medium bullets
    {
        for(int i = 0; i < 8; i++)
        {
            BulletMedium *b1 = new BulletMedium(i);
            b1->setPos(x() + imageOffsetWidth/2 - 10, y() + imageOffsetHeight/2);
            scene()->addItem(b1);
        }
        ++amount;
        playSound(sound);
    }
    else if (amount == 3)   //this is the big bullet
    {
        for(int j = 0; j < 8; j++)
        {
            BulletLarge *b1 = new BulletLarge(j);
            b1->setPos(x() + imageOffsetWidth/2 - 20, y() + imageOffsetHeight/2);
            scene()->addItem(b1);
        }
        ++amount;
        playSound(sound);
    }
    else if (amount > 4)    //this is the pause
    {
        amount = 0;
    }
    else
    {
        ++amount;
    }
}
