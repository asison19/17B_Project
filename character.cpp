#include "character.h"

Character::Character(int sWidth, int sHeight)
{
    //sets character appearance and lives
    this->setPixmap(QPixmap(":/Images/characterImage.png"));
    this->lives = 5;

    //the sound for the shooting
    shootSound = new QMediaPlayer();
    shootSound->setMedia(QUrl("qrc:/Sounds/pew.WAV"));
    shootSound->setVolume(45);

    //the sound for when you're hit
    hitSound = new QMediaPlayer();
    hitSound->setMedia(QUrl("qrc:/Sounds/Down.wav"));

    //the game's scene width and height are passed from constructor given onto here
    this->sceneWidth = sWidth;
    this->sceneHeight = sHeight;

    hitbox = new CharacterHitbox();
    hitbox->setPos(this->x()/2,this->y()/2);
    //scene()->addItem(hitbox); //is there a way to properly add it like this?

    //power x and y for velocity
    pX = 10;
    pY = 10;

    //character images' width and height halved
    offsetOfImageWidth = 10;
    offsetOfImageHeight = 15;

    //character images' width and height
    characterWidth = 30;
    characterHeight = 40;

    capForVelocity = 10;

    velocity = new QVector2D();

    //timer for movement
    timer = new QTimer(this);
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(Move()));
    timer->start(30);
}

Character::~Character()
{

}

//called when key is pressed and changes boolean accordingly
void Character::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        keyUpIsPressed = true;
    }
    if(event->key() == Qt::Key_Down)
    {
        keyDownIsPressed = true;
    }
    if(event->key() == Qt::Key_Left)
    {
        keyLeftIsPressed = true;
    }
    if(event->key() == Qt::Key_Right)
    {
        keyRightIsPressed = true;
    }
    if(event->key() == Qt::Key_Z)
    {
        keyZIsPressed = true;
    }

    if(event->key() == Qt::Key_Shift)
    {
        keyShiftIsPressed = true;
    }
}

//called when key is released and changes boolean accordingly
void Character::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        keyUpIsPressed = false;
    }
    if(event->key() == Qt::Key_Down)
    {
        keyDownIsPressed = false;
    }
    if(event->key() == Qt::Key_Left)
    {
        keyLeftIsPressed = false;
    }
    if(event->key() == Qt::Key_Right)
    {
        keyRightIsPressed = false;
    }
    if(event->key() == Qt::Key_Z)
    {
        keyZIsPressed = false;
    }
    if(event->key() == Qt::Key_Shift)
    {
        keyShiftIsPressed = false;
    }
}

//sets the player in the middle of the game scene
void Character::setStartingPosition()
{
    this->setPos((sceneWidth/2) - offsetOfImageWidth,(sceneHeight/2));
}

//slower movement and velocity setting
void Character::shiftMovement()
{
    if(keyUpIsPressed && !checkIfOutOfBounds(0))
        velocity->setY( velocity->y() -pY/2 );
    if(keyDownIsPressed && !checkIfOutOfBounds(1))
        velocity->setY( velocity->y() +pY/2 );
    if(keyLeftIsPressed && !checkIfOutOfBounds(2))
        velocity->setX( velocity->x() -pX/2 );
    if(keyRightIsPressed && !checkIfOutOfBounds(3))
        velocity->setX( velocity->x() +pX/2 );
    hitbox->setPixmap(QPixmap(":/Images/characterHitbox.png")); //this is to show your hitbox when pressing shift
}

//regular movement and velocity setting
void Character::movement()
{
    if(keyUpIsPressed && !checkIfOutOfBounds(0))
        velocity->setY( velocity->y() -pY );
    if(keyDownIsPressed && !checkIfOutOfBounds(1))
        velocity->setY( velocity->y() +pY );
    if(keyLeftIsPressed && !checkIfOutOfBounds(2))
        velocity->setX( velocity->x() -pX );
    if(keyRightIsPressed && !checkIfOutOfBounds(3))
        velocity->setX( velocity->x() +pX );
    /* Note to Self:
     * if the hitbox is blank using the magic wand, it doesn't work properly...
     * turns out the framework already does it pixel perfect
     * and that what's deleted by the magic wand tool
     * will no longer collide with the item.
     */
    hitbox->setPixmap(QPixmap(":/Images/blankHitbox.png")); //this is to hide characterhitbox when pressing shift
    //hitbox->setPixmap(QPixmap(":/Images/blankHitbox - Copy.png"));
}

//cap for velocity
void Character::velocityCap()
{
    if(velocity->y() > capForVelocity)
        velocity->setY(capForVelocity);
    if(velocity->x() > capForVelocity)
        velocity->setX(capForVelocity);
    if(velocity->y() < -capForVelocity)
        velocity->setY(-capForVelocity);
    if(velocity->x() < -capForVelocity)
        velocity->setX(-capForVelocity);
}

//shoots projectiles that hit enemies
void Character::shootProjectile()
{
    //shoots projectiles to kill enemies
    if(keyZIsPressed)
    {
        Projectile *p1 = new Projectile();
        //p1->setPos(x() + this->pixmap().width()/2,y());
        p1->setPos(x() + 8,y());
        scene()->addItem(p1);
        playSound(shootSound);
    }
}

//this is to check whether the hitbox collides with anything bad
void Character::checkIfHit()
{
    if(hitbox->CollisionCheck())
    {
        --lives;
        qDebug() << lives;
        setStartingPosition();
        recentlyHit = true;
        playSound(hitSound);
        this->setPixmap(QPixmap(":/Images/characterImageHurt.png"));
    }
}

//this checks if the player is outside the playing field
bool Character::checkIfOutOfBounds(int n)
{
    switch (n)
    {
    case 0:
        if(this->y() <= 0)  //checks top
            return true;
        else
            return false;
        break;
    case 1:
        if(this->y() >= sceneHeight - characterHeight) // checks bottom
            return true;
        else
            return false;
        break;
    case 2:
        if(this->x() <= 0)  //checks left
            return true;
        else
            return false;
        break;
    case 3:
        if(this->x() >= sceneWidth - characterWidth) //checks right
            return true;
        else
            return false;
        break;
    default:
        return false;
        break;
    }
}

//plays the hitsound, or the shooting sound depening on situation
void Character::playSound(QMediaPlayer *sound)
{
    if(sound->state() == QMediaPlayer::PlayingState)
    {
        sound->setPosition(0);
    }
    else if(sound->state() == QMediaPlayer::StoppedState)
    {
        sound->play();
    }
}

void Character::Move()
{
    //do nothing if key isn't pressed
    if(keyUpIsPressed == false)
        velocity->setY( 0 );
    if(keyDownIsPressed == false)
        velocity->setY( 0 );
    if(keyLeftIsPressed == false)
        velocity->setX( 0 );
    if(keyRightIsPressed == false)
        velocity->setX( 0 );

    //if key is pressed, move character
    if(keyShiftIsPressed)   //shift is used to halve the speed
        shiftMovement();
    else if (!keyShiftIsPressed)
        movement();

    velocityCap();
    shootProjectile();

    //this adds the hitbox at the first instance of the slot, move()
    //is a workaround since constructor doesn't wanna play with it
    if(!isHitboxThere)
    {
        scene()->addItem(hitbox);
        isHitboxThere = true;
    }

    //checks if the player is recently hit and gives Invulnerable frames if so.
    if(!recentlyHit)
    {
        checkIfHit();
    }
    else if(iFrameAmount >= 0)
    {
        --iFrameAmount;
    }
    else if(iFrameAmount <= 0)
    {
        iFrameAmount = iFrameAmountMax;
        recentlyHit = false;
        this->setPixmap(QPixmap(":/Images/characterImage.png"));
        qDebug() << "iFrames over";
    }

    //this is the actually moving of the character, along with its hitbox
    setPos( x() + velocity->x(), y() + velocity->y()  );
    hitbox->setPos(this->x() + offsetOfImageWidth,this->y() + offsetOfImageHeight);
}

