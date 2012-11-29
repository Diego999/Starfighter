#ifndef ENUMERATION_H
#define ENUMERATION_H

enum Action
{
    Top = 1,
    Bottom = 2,
    Shoot = 3,
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

#endif // ENUMERATION_H
