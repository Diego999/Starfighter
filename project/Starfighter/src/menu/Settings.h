#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Action.h"
#include "GameEngine.h"
#include "Qt/QString.h"

class Settings
{
private:
	int musicVolume;

	int soundEffectsVolume;

	Qt::QString playerOneName;

	Qt::QString playerTwoName;

	Action playerOneControls;

	Action playerTwoControls;

	GameEngine gameEngine;

public:
	boolean save(Qt::QString file);

	boolean load(Qt::QString file);

	int musicVolume();

	int soundEffectsVolume();

	Qt::QString playerOneName();

	Qt::QString playerTwoName();

	Action playerOneControls();

	Action playerTwoControls();

	boolean setMusicVolume(int volume);

	boolean setSoundEffectsVolume(int volume);

	boolean setPlayerOneName(Qt::QString name);

	boolean setPlayerTwoName(Qt::QString name);

	boolean setPlayerOneControls(Action controls);

	boolean setPlayerTwoControls(Action controls);

};
#endif
