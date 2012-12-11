#ifndef DISPLAY_ENGINE_H
#define DISPLAY_ENGINE_H

#include "include/game/Displayable.h"
#include "include/engine/GameEngine.h"

class Asteroid;
class Projectile;
class Bonus;
class Spaceship;
class AlienSpaceship;
class Supernova;

class DisplayEngine : public QWidget
{
    Q_OBJECT
public:
    DisplayEngine(GameEngine *ge,QWidget *parent);
    ~DisplayEngine();

    QRect   sceneSize() const;
    QPoint  warzoneValueMin() const;
    QPoint  warzoneValueMax() const;

    void setProgressHP1(int _value);
    void setProgressHP2(int _value);
    void setProgressShield1(int _value);
    void setProgressShield2(int _value);

    void addProjectile(Projectile *_inProjectile);
    void addShip(Spaceship *_inSpaceship);  
    void addAsteroid(Asteroid *_inAsteroide);
    void addSmallAsteroid(Asteroid *_inAsteroide);
    void addBonus(Bonus *_inBonus);
    void addAlienSpaceship(AlienSpaceship *_inAlienSpaceship);
    void addSupernova(Supernova *_inSupernova);

    void timerEvent(QTimerEvent *);

protected:
    //void paintEvent(QPaintEvent * event);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void updateScreen();

private:
    void gameType();
    void creatHUD();
    void switchFullScreen();
    void updateGameData();
    void endGame();
    void escapeGame();

    void checkOutsideScene(QList<Displayable*> &list);
    void checkPlayerOutsideScene(QList<Spaceship*> &list);
    void clearList(QList<Displayable*> &list);
    bool checkCollisionItemAndList(const int i_list1,QList<Displayable*> &list1,QList<Displayable*> &list2);
    bool checkCollisionSpaceshipAndList(const int i_list1,QList<Displayable*> &list);

    void recoveryTime();

    QGraphicsScene * scene;
    QGraphicsView * view;

    QWidget * mainPart;
    QWidget * downHUD;


    QList<Displayable*>  listProjectile;
    QList<Displayable*>  listAsteroide;
    QList<Displayable*>  listSmallAsteroide;
    QList<Displayable*>  listBonus;
    QList<Spaceship*>    listSpaceship;
    QList<Displayable*>  listAlienSpaceship;
    QList<Displayable*>  listSupernova;

    //QList<Displayable*> listDisplayable;
    //Displayable*        displayable[];

    GameEngine *gameEngine;

    // dimension of the screeen
    int screenSizeWidth;
    int screenSizeHeight;

    double sceneWidth;
    double sceneHeigth;

    // widget used for the HUD
    QLCDNumber * timer;
    QLCDNumber * scoreP1;
    QLCDNumber * scoreP2;

    QProgressBar * HP1;
    QProgressBar * HP2;
    QProgressBar * shield1;
    QProgressBar * shield2;

    //swtich fullscreen <->
    bool isFullScreen;
    bool isTimer;
};
#endif
