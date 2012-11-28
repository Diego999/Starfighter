#include "include/utils/Settings.h"

Settings::Settings(GameEngine *ge)
{

}

bool Settings::save(QString file)
{
	return 0;
}

bool Settings::load(QString file)
{
	return 0;
}

int Settings::musicVolume()
{
	return 0;
}

int Settings::soundEffectsVolume()
{
	return 0;
}

QString Settings::playerOneName()
{
	return 0;
}

QString Settings::playerTwoName()
{
	return 0;
}

Action Settings::playerOneControls()
{
    return Top;
}

Action Settings::playerTwoControls()
{
    return Top;
}

bool Settings::setMusicVolume(int volume)
{
	return 0;
}

bool Settings::setSoundEffectsVolume(int volume)
{
	return 0;
}

bool Settings::setPlayerOneName(QString name)
{
	return 0;
}

bool Settings::setPlayerTwoName(QString name)
{
	return 0;
}

bool Settings::setPlayerOneControls(Action controls)
{
	return 0;
}

bool Settings::setPlayerTwoControls(Action controls)
{
	return 0;
}
