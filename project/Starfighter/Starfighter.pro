######################################################################
# Automatically generated by qmake (2.01a) ven. 14. d�c. 13:08:31 2012
######################################################################

TEMPLATE = app
TARGET = 
PRECOMPILED_HEADER = include\stable.h
DEPENDPATH += . \
              include \
              src \
              include\engine \
              include\enum \
              include\game \
              include\menu \
              include\utils \
              res\ui \
              src\engine \
              src\game \
              src\menu \
              src\utils
INCLUDEPATH += .

# Input
HEADERS += include/stable.h \
           include/engine/DisplayEngine.h \
           include/engine/GameEngine.h \
           include/engine/SoundEngine.h \
           include/engine/SpawnEngine.h \
           include/engine/UserControlsEngine.h \
           include/enum/Enum.h \
           include/game/AlienSpaceship.h \
           include/game/Asteroid.h \
           include/game/Bonus.h \
           include/game/BonusForceField.h \
           include/game/BonusHP.h \
           include/game/BonusProjectile.h \
           include/game/BonusSpeed.h \
           include/game/Destroyable.h \
           include/game/Displayable.h \
           include/game/Obstacle.h \
           include/game/Projectile.h \
           include/game/ProjectileAlien.h \
           include/game/ProjectileCross.h \
           include/game/ProjectileSimple.h \
           include/game/ProjectileV.h \
           include/game/Spaceship.h \
           include/game/Supernova.h \
           include/menu/AboutDialog.h \
           include/menu/MainDialog.h \
           include/menu/NewGameDialog.h \
           include/menu/OptionsDialog.h \
           include/menu/SetKeyDialog.h \
           include/utils/Settings.h \
    include/config/Define.h
FORMS += res/ui/AboutDialog.ui \
         res/ui/MainDialog.ui \
         res/ui/NewGameDialog.ui \
         res/ui/OptionsDialog.ui
SOURCES += src/main.cpp \
           src/engine/DisplayEngine.cpp \
           src/engine/GameEngine.cpp \
           src/engine/SoundEngine.cpp \
           src/engine/SpawnEngine.cpp \
           src/engine/UserControlsEngine.cpp \
           src/game/AlienSpaceship.cpp \
           src/game/Asteroid.cpp \
           src/game/Bonus.cpp \
           src/game/BonusForceField.cpp \
           src/game/BonusHP.cpp \
           src/game/BonusProjectile.cpp \
           src/game/BonusSpeed.cpp \
           src/game/Destroyable.cpp \
           src/game/Displayable.cpp \
           src/game/Obstacle.cpp \
           src/game/Projectile.cpp \
           src/game/ProjectileAlien.cpp \
           src/game/ProjectileCross.cpp \
           src/game/ProjectileSimple.cpp \
           src/game/ProjectileV.cpp \
           src/game/Spaceship.cpp \
           src/game/Supernova.cpp \
           src/menu/AboutDialog.cpp \
           src/menu/MainDialog.cpp \
           src/menu/NewGameDialog.cpp \
           src/menu/OptionsDialog.cpp \
           src/menu/SetKeyDialog.cpp \
           src/utils/Settings.cpp
RESOURCES += ressources.qrc
TRANSLATIONS += starfighter_fr.ts
QT += opengl
