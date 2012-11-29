#ifndef SETTINGS_H
#define SETTINGS_H

#include "include/enum/Enum.h"
#include <QSettings>
class QObject;
class QString;

class Settings
{
    //Q_OBJECT

public:
    static Settings& getGlobalSettings();

	int musicVolume();
	int soundEffectsVolume();
	
	QString playerOneName();
	QString playerTwoName();

	Action playerOneControls();
	Action playerTwoControls();

    void setMusicVolume(int volume);
    void setSoundEffectsVolume(int volume);
    void setPlayerOneName(QString name);
    void setPlayerTwoName(QString name);
    void setPlayerOneControls(Action controls);
    void setPlayerTwoControls(Action controls);
	
private:
    Settings();
    ~Settings();
    Settings(Settings const&);      // Don't Implement
    void operator=(Settings const&);// Don't implement

    QSettings* qse;
};

#endif
