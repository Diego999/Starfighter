#ifndef DISPLAY_ENGINE_H
#define DISPLAY_ENGINE_H

#include "include/game/Displayable.h"
#include "include/engine/GameEngine.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLCDNumber>
#include <QProgressBar>

class DisplayEngine : public QObject
{
    Q_OBJECT
public:
    DisplayEngine(int width, int height, GameEngine *ge);
    ~DisplayEngine();
	
    QRect sceneSize();
    void setProgressHP1(int _value);
    void setProgressHP2(int _value);
    void setProgressShield1(int _value);
    void setProgressShield2(int _value);

private:
    void gameType();
    void updateGameData();
    void endGame();

protected:
    void timerEvent(QTimerEvent * event);
	
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QWidget * mainPart;

    Displayable* displayable[];
    GameEngine *gameEngine;

    QLCDNumber * timer;
    QLCDNumber * scoreP1;
    QLCDNumber * scoreP2;

    QProgressBar * HP1;
    QProgressBar * HP2;
    QProgressBar * shield1;
    QProgressBar * shield2;
};
#endif
