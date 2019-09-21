#include "projectile.h"

Projectile::Projectile()
{
    //setting the projectiles' apperance, damage, and velocity
    this->setPixmap(QPixmap(":/Images/characterProjectile.png"));
    damage = 1;
    velocity = new QVector2D(0,-40);

    //creating and starting timer to move the projectile
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Move()));
    timer->start(30);

    //this->speed = 30;
    setTransformOriginPoint(this->pixmap().width()/2, this->pixmap().height()/2);
}

Projectile::~Projectile()
{

}

void Projectile::Move()
{
    //actual moving
    this->setPos(x() + velocity->x(), y() + velocity->y());

    //this checks if the projectile is offscreen, and deletes it
    if(y()<= -100)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }

    //checking for collision between this, projectile, and the enemies.
    QList<QGraphicsItem*> colliding_Items = collidingItems();
    int n = colliding_Items.length();
    for(int i =0; i < n; i++)
    {
        if(typeid(*(colliding_Items[i])) == typeid(Enemy_1)) //checks if enemy 1 collides with projectile
        {
            Enemy_1 *e = (Enemy_1*)colliding_Items[i];
            e->takeDamage(damage);
            scene()->removeItem(this);
            delete this;
            return;
        }
        else if(typeid(*(colliding_Items[i])) == typeid(Enemy_2)) //checks if enemy 2 collides with the projectile
        {
            Enemy_2 *e = (Enemy_2*)colliding_Items[i];
            e->takeDamage(damage);
            scene()->removeItem(this);
            delete this;
            return;
        }
        else if(typeid(*(colliding_Items[i])) == typeid(Enemy_Boss))    //checks if Boss collides with the projectile
        {
            Enemy_Boss *e = (Enemy_Boss*)colliding_Items[i];
            e->takeDamage(damage);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
}

