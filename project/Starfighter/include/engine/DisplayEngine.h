#ifndef DISPLAY_ENGINE_H
#define DISPLAY_ENGINE_H

#include "include/game/Displayable.h"
#include "include/engine/GameEngine.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLCDNumber>
#include <QProgressBar>

class Asteroid;
class Projectile;

class DisplayEngine : public QWidget
{
    Q_OBJECT
public:
    //DisplayEngine(QWidget *parent);
    DisplayEngine(GameEngine *ge,QWidget *parent);
    ~DisplayEngine();

    QRect   sceneSize();
    QPoint  warzoneValue();
    void setProgressHP1(int _value);
    void setProgressHP2(int _value);
    void setProgressShield1(int _value);
    void setProgressShield2(int _value);

    void addProjectile(Projectile *_inProjectile);
    void addShip(Spaceship *_inSpaceship);  
    void addAsteroide(Asteroid *_inAsteroide);
    void addBonus(Bonus *_inBonus);
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

    void recoveryTime();

    QGraphicsScene * scene;
    QGraphicsView * view;

    QWidget * mainPart;
    QWidget * downHUD;


    QList<Projectile*>      listProjectile;
    QList<Asteroid*>        listAsteroide;
    QList<Bonus*>           listBonus;
    QList<Spaceship*>       listSpaceship;

    QList<Displayable*> listDisplayable;
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
