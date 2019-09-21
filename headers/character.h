#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QVector2D>

#include <QMediaPlayer>
#include <QUrl>

#include "projectile.h"
#include "characterhitbox.h"

class Character : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:    //unsigned int moveSpeed;
    QTimer * timer;
    QVector2D * velocity;
    int lives;

    QMediaPlayer *shootSound;
    QMediaPlayer *hitSound;

    //QGraphicsPixmapItem hitbox;
    CharacterHitbox *hitbox;
    //Projectile *hitbox;

    //powers for the velocity mechanic
    float pX;
    float pY;

    // character's width and height halved, used for it's hitbox
    int offsetOfImageWidth;
    int offsetOfImageHeight;

    //character image's width and height, used for out of bounds checking
    int characterWidth;
    int characterHeight;

    //movement keys booleans
    bool keyUpIsPressed = false;
    bool keyDownIsPressed = false;
    bool keyLeftIsPressed = false;
    bool keyRightIsPressed = false;
    bool keyZIsPressed = false;
    bool keyShiftIsPressed = false; //used to slow character down for more precise dodging

    //checking for hitbox being there, used for adding hitbox in a roundabout way,
    //since it cannot be added in the constructor
    bool isHitboxThere = false;

    //gamelevel's passed in width and height
    int sceneWidth;
    int sceneHeight;

    int capForVelocity; //cap for the movement of the character

    //these are used to give the player invulnerability frames just after getting hit
    bool recentlyHit = false;
    int iFrameAmountMax = 100;
    int iFrameAmount = iFrameAmountMax;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    //various player options, including movement and shooting
    void shiftMovement();
    void movement();
    void velocityCap();
    void shootProjectile();

    //polishment to check if character is hit or out of bounds
    //the latter does no damage and is to keep player from being cheeky
    void checkIfHit();
    bool checkIfOutOfBounds(int n);

    void playSound(QMediaPlayer * sound);

public:
    Character(int sceneWidth, int sceneHeight);
    //Character(unsigned short moveSpeed);
    ~Character();
    void setStartingPosition();

signals:
public slots:
    virtual void Move();

};

#endif // CHARACTER_H
