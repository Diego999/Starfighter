#ifndef SETTINGS_H
#define SETTINGS_H

#include "include/enum/Enum.h"
#include "include/engine/GameEngine.h"

class Settings
{
    Q_OBJECT

public:
    Settings(GameEngine *ge);
	
	bool save(QString file);
	bool load(QString file);
	int musicVolume();
	int soundEffectsVolume();
	
	QString playerOneName();
	QString playerTwoName();

	Action playerOneControls();
	Action playerTwoControls();

	bool setMusicVolume(int volume);
	bool setSoundEffectsVolume(int volume);
	bool setPlayerOneName(QString name);
	bool setPlayerTwoName(QString name);
	bool setPlayerOneControls(Action controls);
	bool setPlayerTwoControls(Action controls);
	
private:
    int musicVolume;
    int soundEffectsVolume;

    QString playerOneName;
    QString playerTwoName;

    Action playerOneControls;
    Action playerTwoControls;

    GameEngine *gameEngine;
};
#endif
