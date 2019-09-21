#include "enemy_2.h"

Enemy_2::Enemy_2(int version)
{
    //sets the image, image sizes, hp and velocity
    this->setPixmap(QPixmap(":/Images/enemy_2_Image.png"));
    imageOffsetWidth = 30;
    imageOffsetHeight = 40;
    this->hp = 18;
    velocity = new QVector2D(0 , 3);

    this->version = version;

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

    //timer for the bullets
    bulletTimer = new QTimer(this);
    connect(bulletTimer,
            SIGNAL(timeout()),
            this,
            SLOT(Shoot()));
    bulletTimer->start(1000);
}

//moves the enemy depending on version
void Enemy_2::Move()
{
    //qDebug() << "enemy_1_move";
    setPos(x()+velocity->x(), y()+velocity->y());
    if(version == 0)    //this moves the enemy to go rightmore
    {
        velocity->setX(velocity->x()+0.01);
    }
    if(version == 1)    //this moves the enemy to go leftmore
    {
        velocity->setX(velocity->x()-0.01);
    }
    checkIfOutOfBounds();
}

//shoots bulletmedium 8 times in a circle
void Enemy_2::Shoot()
{
    for(int i = 0; i < 8; i++)
    {
        BulletMedium *b1 = new BulletMedium(i);
        b1->setPos(x() + 10, y() + 10);
        scene()->addItem(b1);
    }
    playSound(sound);
}
