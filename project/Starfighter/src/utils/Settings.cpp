#include "include/utils/Settings.h"
#include <QSettings>
#include <QMap>
#include <QStringListIterator>

#ifdef Q_WS_MAC
    #define ORGANIZATION "ch.hearc"
#else
    #define ORGANIZATION "HE-Arc"
#endif

#define APPLICATION "Starfighter"

#define P1_NAME "p1n"
#define P2_NAME "p2n"
#define PLAYERS_CONTROLS "controls"
#define MUSIC_VOLUME "mvol"
#define SOUNDEFFECTS_VOLUME "sevol"

const int kDefaultMusicVolume = 50;
const int kDefaultSoundEffectsVolume = 50;
QString kDefaultPlayerOneName = QObject::tr("Player 1");
QString kDefaultPlayerTwoName = QObject::tr("Player 2");

Settings::Settings()
{
    qse = new QSettings(ORGANIZATION, APPLICATION);
}

Settings::~Settings()
{
    delete qse;
    qDebug("destroy");
}

Settings& Settings::getGlobalSettings()
{
    static Settings globalSettings;

    return globalSettings;
}

int Settings::musicVolume()
{
    bool ok;
    int volume = qse->value(MUSIC_VOLUME, kDefaultMusicVolume).toInt(&ok);
    return ok ? volume : kDefaultMusicVolume;
}

int Settings::soundEffectsVolume()
{
    bool ok;
    int volume = qse->value(SOUNDEFFECTS_VOLUME, kDefaultSoundEffectsVolume).toInt(&ok);
    return ok ? volume : kDefaultSoundEffectsVolume;
}

QString Settings::playerOneName()
{
    return qse->value(P1_NAME, kDefaultPlayerOneName).toString();
}

QString Settings::playerTwoName()
{
    return qse->value(P2_NAME, kDefaultPlayerTwoName).toString();
}

QMap<Action, Qt::Key> Settings::playersControls()
{
    QMap<Action, Qt::Key> defaultControls;

    defaultControls[Top1] = Qt::Key_W;
    defaultControls[Top2] = Qt::Key_Up;
    defaultControls[Bottom1] = Qt::Key_S;
    defaultControls[Bottom2] = Qt::Key_Down;
    defaultControls[Shoot1] = Qt::Key_E;
    defaultControls[Shoot2] = Qt::Key_Enter;
    defaultControls[Escape] = Qt::Key_Escape;

    QMap<Action, Qt::Key> controls;

    qse->beginGroup(PLAYERS_CONTROLS);
    QStringListIterator it(qse->childKeys());
    while (it.hasNext())
    {
        bool ok;
        QString key = it.next();
        Action ind = (Action)key.toInt(&ok);
        if(ok)
        {
            Qt::Key value = (Qt::Key)qse->value(key, defaultControls[ind]).toInt(&ok);
            controls[ind] = ok ? value : defaultControls[ind];
        }
    }
    qse->endGroup();

    return controls;
}

void Settings::setMusicVolume(int volume)
{
    qse->setValue(MUSIC_VOLUME, volume);
}

void Settings::setSoundEffectsVolume(int volume)
{
    qse->setValue(SOUNDEFFECTS_VOLUME, volume);
}

void Settings::setPlayerOneName(QString name)
{
    qse->setValue(P1_NAME, name);
}

void Settings::setPlayerTwoName(QString name)
{
    qse->setValue(P2_NAME, name);
}

void Settings::setPlayersControls(QMap<Action, Qt::Key> controls)
{
    qse->beginGroup(PLAYERS_CONTROLS);
    QMapIterator<Action, Qt::Key> i(controls);
    while (i.hasNext())
    {
        i.next();
        qse->setValue(QString().setNum(i.key()), i.value());
    }
    qse->endGroup();
}
