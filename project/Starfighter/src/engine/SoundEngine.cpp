#include "include/engine/SoundEngine.h"

SoundEngine::SoundEngine(int soundEffectsVolume, int musicVolume, QObject *parent) :
    QObject(parent), satCounter(0)
{
    Phonon::AudioOutput *shootOutput = new Phonon::AudioOutput(Phonon::GameCategory, this);
    shootOutput->setVolume(soundEffectsVolume / 100.0);
    Phonon::AudioOutput *satOutput = new Phonon::AudioOutput(Phonon::GameCategory, this);
    satOutput->setVolume(soundEffectsVolume / 100.0);

    Phonon::AudioOutput *musicOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    musicOutput->setVolume(musicVolume / 100.0);

    shootMediaObject = new Phonon::MediaObject(this);
    shootMediaObject->setCurrentSource(Phonon::MediaSource(":/sounds/laser"));
    Phonon::createPath(shootMediaObject, shootOutput);

    satMediaObject = new Phonon::MediaObject(this);
    satMediaObject->setCurrentSource(Phonon::MediaSource(":/sounds/sat"));
    Phonon::createPath(satMediaObject, satOutput);

    musicMediaObject = new Phonon::MediaObject(this);
    musicMediaObject->setCurrentSource(Phonon::MediaSource(":/sounds/bgmusic"));
    Phonon::createPath(musicMediaObject, musicOutput);
    connect(musicMediaObject, SIGNAL(aboutToFinish()), this, SLOT(musicFinished()));
    musicMediaObject->play();
}

void SoundEngine::playSound(Sounds toPlay)
{
    if(toPlay == SatelliteSound)
    {
        if(++satCounter <= 1)
        {
            playSat();
            QTimer::singleShot(SAT_INTERVAL, this, SLOT(playSat()));
        }
    }
    else if(toPlay == ShootSound)
    {
        shootMediaObject->seek(0);
        shootMediaObject->play();
    }
}

void SoundEngine::stopSound(Sounds toStop)
{
    if(toStop == SatelliteSound)
        --satCounter;
}

void SoundEngine::playSat()
{
    if(satCounter > 0)
    {
        satMediaObject->seek(0);
        satMediaObject->play();

        QTimer::singleShot(SAT_INTERVAL, this, SLOT(playSat()));
    }
}

void SoundEngine::musicFinished()
{
    musicMediaObject->enqueue(Phonon::MediaSource(":/sounds/bgmusic"));
}
