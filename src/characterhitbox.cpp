#include "characterhitbox.h"

CharacterHitbox::CharacterHitbox()
{
    //this->setPixmap(QPixmap(":/Images/blankHitbox.png"));
}

CharacterHitbox::~CharacterHitbox()
{

}

//this checks the collision between the character's hitbox and the bullets and enemy
bool CharacterHitbox::CollisionCheck()
{
    QList<QGraphicsItem*> colliding_Items = collidingItems();
    int n = colliding_Items.length();
    for(int i =0; i < n; i++)
    {
        //this checks if character collides with either a bullet or enemy
        if(typeid(*(colliding_Items[i])) == typeid(BulletMedium)
                || typeid(*(colliding_Items[i])) == typeid(BulletLarge)
                || typeid(*(colliding_Items[i])) == typeid(Enemy_1)
                || typeid(*(colliding_Items[i])) == typeid(Enemy_2)
                || typeid(*(colliding_Items[i])) == typeid(Enemy_Boss))
        {
            //BulletMedium *b = (BulletMedium*)colliding_Items[i];
            //b->TakeDamage(damage);
            //scene()->removeItem(this);
            //delete this;
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
