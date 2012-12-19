#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include "include/enum/Enum.h"

#define SAT_INTERVAL 1500

class SoundEngine : public QObject
{
    Q_OBJECT
public:
    explicit SoundEngine(int soundEffectsVolume, int musicVolume, QObject *parent = 0);
    
signals:

private:
    int satCounter;
    Phonon::MediaObject *satMediaObject;
    Phonon::MediaObject *shootMediaObject;
    Phonon::MediaObject *musicMediaObject;

private slots:
    void playSat();
    void musicFinished();
    
public slots:
    void playSound(Sounds);
    void stopSound(Sounds);
    
};

#endif // SOUNDENGINE_H
