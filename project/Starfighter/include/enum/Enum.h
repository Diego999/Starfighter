#ifndef ENUMERATION_H
#define ENUMERATION_H

enum Action
{
    Top1 = 11,
    Top2 = 12,
    Bottom1 = 21,
    Bottom2 = 22,
    Shoot1 = 31,
    Shoot2 = 32,
    Escape = 4
};

enum Shooter
{
    Player1 = 1,Player2 = 2,Other = 3
};

enum TypeProjectiles
{
    ProjSimple = 1,ProjCross = 2,ProjV = 3,ProjAlien = 4,Nothing = 5
};

enum GameMode
{
    Timer = 1,DeathMatch = 2
};

enum SpaceshipType
{
    SpaceshipType1 = 1, SpaceshipType2 = 2
};

enum Difficulty
{
    Asteroids = 0x00000001, AlienMothership = 0x00000010, Satellites = 0x00000100, Supernovae = 0x00001000
};

#endif // ENUMERATION_H
