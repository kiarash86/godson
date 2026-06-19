#include "../../../include/model/abilities/littleTaha/bloodSerum.h"

bloodSerum::bloodSerum(card *owner) : ability(owner, 4) {};

void bloodSerum::excute(gameData gameData)
{
    gameData.effects.push_back(new healEffect{gameData.team[gameData.targetIndex] , 40 , 2});
}