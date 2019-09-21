#include "enemy_1.h"

Enemy_1::Enemy_1()
{
    //sets the enemies' appearance, image sizes hp and velocity
    this->setPixmap(QPixmap(":/Images/enemy_1_Image.png"));
    imageOffsetWidth = 30;
    imageOffsetHeight = 40;
    this->hp = 16;
    velocity = new QVector2D(0 , 5);

    //sound for dying and shooting
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/Sounds/Buzzer1.wav"));

    //timer for the move slot
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
    bulletTimer->start(1000);
}

//move the enemy from top to bottom
void Enemy_1::Move()
{
    //qDebug() << "enemy_1_move";
    setPos(x()+velocity->x(), y()+velocity->y());
    checkIfOutOfBounds();
}

//shoots four bullets in a diagonal pattern like an X
void Enemy_1::Shoot()
{
    for(int i = 1; i < 8; i+=2)
    {
        BulletMedium *b1 = new BulletMedium(i);
        b1->setPos(x() + 10, y() + 10);
        scene()->addItem(b1);
    }
    playSound(sound);
}

