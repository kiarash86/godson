#include "../../../include/model/abilities/drWhite/doping.h"



doping::doping(card *owner) : ability(owner, 4) {};

void doping::excute(gameData gameData) 
{
    gameData.team[gameData.targetIndex]->setBuffDmg(1.2 ,2);
}