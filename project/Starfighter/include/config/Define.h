#ifndef DEFINE_H
#define DEFINE_H

#include "include/enum/Enum.h"

//DisplayEngine
#define SPACE_BETWEEN                       250
#define SPACE_INPLAYER                      50
#define BACKGROUND                          "" //A METTRE

//SpawnEngine
#define SPAWN_INTERVAL                      400
#define RESISTANCE_ASTEROID                 20
#define RESISTANCE_ALIEN                    20
#define ALIEN_SWIRL_MIN                     10
#define ALIEN_SWIRL_MAX                     20
#define BONUS_HEALTH_MIN                    30
#define BONUS_HEALTH_MAX                    50
#define MAX_SPACESHIP_PV                    100
#define BONUS_PROJECTILE_DURATION           10000
#define BONUS_TYPE_PROJECTILES_MIN          2
#define BONUS_TYPE_PROJECTILES_MAX          4
#define BONUS_SPEED_MIN                     8
#define BONUS_SPEED_MAX                     20
#define BONUS_SPEED_DURATION                10000

//UserControlsEngine
#define REFRESH                             10
#define NOVATIMER                           10000 // (ms)

//AlienSpaceShip
#define MARGIN_Y                            10
#define DELTA_X                             100

//Asteroid
#define SPEED_ASTEROID                      1
#define MAX_ASTEROID                        5
#define MIN_ASTEROID                        3
#define POWER_ASTEROID                      10
#define POWER_SMALL_ASTEROID                5
#define RESISTANCE_SMALL_ASTEROID           1
#define HEALTHPOINT_SMALL_ASTEROID          50

//Bonus
#define DELTA_X_B                           100
#define SOUND_TIMER                         1000 // (ms)

//Projectile
#define RADIUS_PROJECTILE                   10

//ProjectileAlien
#define POWER_ALIEN                         1000

//ProjectileCross
#define POWER_CROSS                         1000
#define SPEED_CROSS_DEF                     10

//ProjectileSimple
#define POWER_SIMPLE                        1000
#define SPEED_SIMPLE_DEF                    10

//ProjectileV
#define POWER_V                             1000
#define SPEED_V_DEF                         5

//Spaceship
//PV -> cf SpawnEngine
#define MAX_SPACESHIP_BONUS                 2
#define AMPLI_SPACESHIP_PROJ_V              60.0
#define OMEGA_SPACESHIP_PROJ_V              3.0
#define PROJ_SPACESHIP_DEF                  ProjSimple
#define RESISTANCE_FORCE_FIELD              100

#define HEALTHPOINT_1                       100
#define HEALTHPOINT_2                       100
#define RESISTANCE_1                        100
#define RESISTANCE_2                        100
#define SPEED_1                             5
#define SPEED_2                             5

//Supernova
#define NB_SPIRAL                           90

#endif // DEFINE_H
