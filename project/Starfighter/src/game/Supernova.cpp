#include "include/game/Supernova.h"

Supernova::Supernova(int x, int y,GameEngine *ge):Displayable(x,y),Obstacle(x,y),gameEngine(ge)
{
}

Supernova::~Supernova()
{

}
