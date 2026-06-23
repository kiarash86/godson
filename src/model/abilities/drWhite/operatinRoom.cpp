#include "../../../../include/model/abilities/drWhite/operationRoom.h"

void operationRoom::reriveChosenTeammate(card *teammate)
{
    if (teammate == nullptr)
    {
        return;
    }

    teammate->heal(200);
}

operationRoom::operationRoom(card *owner) : ability(owner, "operationRoom", 4, 4, true, true, true, true) {}

bool operationRoom::excute(gameData gameData)
{
    if (gameData.team.empty() || gameData.targetIndex < 0 || gameData.targetIndex >= static_cast<int>(gameData.team.size()))
    {
        return false;
    }

    reriveChosenTeammate(gameData.team[gameData.targetIndex]);
    return true;
}
