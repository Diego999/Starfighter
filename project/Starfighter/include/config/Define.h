#ifndef DEFINE_H
#define DEFINE_H

#include "include/enum/Enum.h"

//Modifiable

//DisplayEngine
#define BACKGROUND                          ":/images/game/background"
#define ICON_BATTACK                        ":/images/game/icon/attack"
#define ICON_BSPEED                         ":/images/game/icon/speed"

//SpawnEngine
#define PROB_ASTEROID                       100
#define PROB_ALIEN                          50
#define PROB_SAT                            20
#define PROB_SUPERNOVA                      1

#define SPAWN_INTERVAL                      400 // (ms)
#define RESISTANCE_ASTEROID                 20
#define RESISTANCE_ALIEN                    20
#define ALIEN_SWIRL_MIN                     10
#define ALIEN_SWIRL_MAX                     20
#define BONUS_HEALTH_MIN                    30
#define BONUS_HEALTH_MAX                    50
#define MAX_SPACESHIP_PV                    100
#define BONUS_PROJECTILE_DURATION           10000 // (ms)
#define BONUS_TYPE_PROJECTILES_MIN          2 // ProjCross
#define BONUS_TYPE_PROJECTILES_MAX          3 //ProjV
#define BONUS_SPEED_MIN                     8 //Nb Px
#define BONUS_SPEED_MAX                     20 //Nb Px
#define BONUS_SPEED_DURATION                10000 // (ms)

//UserControlsEngine
#define REFRESH                             17 // (ms)
#define NOVATIMER                           10000 // (ms)

//AlienSpaceShip
#define PICTURE_ALIENSPACESHIP              ":/images/game/mothership"
#define NB_POINT_ALIENSPACESHIP             500
#define ARG_INCREMENTATION_ALIENSPACESHIP   0.0005 // rad

//Asteroid
#define SPEED_ASTEROID                      3 //Factor
#define SPEED_SMALL_ASTEROID                3 //Factor, keep the same than SPEED_ASTEROID
#define MAX_ASTEROID                        5 //Number max of small asteroids
#define MIN_ASTEROID                        3 //Number min of small asteroids
#define DELTA_ANGLE_BETWEEN_180_AXES        M_PI/3

#define POWER_ASTEROID                      10
#define POWER_SMALL_ASTEROID                5
#define RESISTANCE_SMALL_ASTEROID           1 // Min : 1 Max : 100
#define HEALTHPOINT_SMALL_ASTEROID          50

#define NUMBER_FRAME_BEFORE_CHANGING_PIC    2

#define NB_POINT_ASTEROID                   50
#define NB_POINT_SMALL_ASTEROID             80

#define PICTURE_ASTEROID                    ":/images/game/asteroids/rock%1"
#define NB_PICTURE_ASTEROID_MIN             10000
#define NB_PICTURE_ASTEROID_MAX             10031

#define PICTURE_SMALL_ASTEROID              ":/images/game/asteroids/rock%1"
#define NB_PICTURE_SMALL_ASTEROID_MIN       20000
#define NB_PICTURE_SMALL_ASTEROID_MAX       20031

//Bonus
#define SOUND_TIMER                         1000 // (ms)
#define PICTURE_BONUS                       ":/images/game/bonus"
#define NB_POINT_BONUS                      300
#define ARG_INCREMENTATION_BONUS            0.0010 // rad

//Projectile
#define RADIUS_PROJECTILE                   10 // px
#define NB_POINT_PROJECTILE                 10 //When a spaceship touchs another one

//ProjectileAlien
//Power is the same for supernova and AlienSpaceShip
#define POWER_ALIEN                         1000
#define MODULE_INCREMENT_ALIEN              4.0

//ProjectileCross
#define POWER_CROSS                         1000
#define SPEED_CROSS_DEF                     20 // dx
#define SLOPE_CROSS                         M_PI/16

//ProjectileSimple
#define POWER_SIMPLE                        1000
#define SPEED_SIMPLE_DEF                    20 // dx

//ProjectileV
#define POWER_V                             1000
#define SPEED_V_DEF                         20 // dx

//Spaceship
//PV -> cf SpawnEngine
#define MAX_SPACESHIP_BONUS                 2
#define AMPLI_SPACESHIP_PROJ_V              20.0 //px
#define OMEGA_SPACESHIP_PROJ_V              0.040 // rad/s
#define PROJ_SPACESHIP_DEF                  ProjSimple
#define RESISTANCE_FORCE_FIELD              100

#define PICTURE_SPACESHIP_1                 ":/images/game/spaceship"
#define PICTURE_SPACESHIP_2                 ":/images/game/spaceship"
#define HEALTHPOINT_1                       100
#define HEALTHPOINT_2                       100
#define RESISTANCE_1                        100
#define RESISTANCE_2                        100
#define SPEED_1                             5 // dy
#define SPEED_2                             5 // dy

//Supernova
#define NB_SPIRAL                           90

//Do not touch

//DisplayEngine
#define SPACE_BETWEEN                       250
#define SPACE_INPLAYER                      50

//AlienSpaceShip
#define MARGIN_Y                            10
#define DELTA_X_MIN                         50
#define DELTA_X                             200 //Cf Specification file

//Bonus
#define DELTA_X_B                           100 //Cf Specification file


#endif // DEFINE_H
