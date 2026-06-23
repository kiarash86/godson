#include "../../../../include/model/abilities/drWhite/doping.h"

doping::doping(card *owner) : ability(owner, "doping", 4, 0, true, true, false, false) {}

bool doping::excute(gameData gameData)
{
    if (gameData.team.empty() || gameData.targetIndex < 0 || gameData.targetIndex >= static_cast<int>(gameData.team.size()))
    {
        return false;
    }

    if (gameData.team[gameData.targetIndex] == nullptr)
    {
        return false;
    }

    gameData.team[gameData.targetIndex]->setBuffDmg(1.2f, 2);
    return true;
}
