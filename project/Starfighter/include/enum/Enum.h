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
    Player1,Player2,Other
};

enum TypeProjectiles
{
    ProjectileSimple,ProjectileCross,ProjectileV,ProjectileAlien,Nothing
};

enum GameMode
{
    Timer,DeathMatch
};

#endif // ENUMERATION_H
