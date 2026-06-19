#include "../../../include/model/abilities/drWhite/operationRoom.h"


void operationRoom::reriveChosenTeammate(card * teammate)
{
    teammate->heal(200);
    //TODO
    //deleting bads buffs
}
operationRoom::operationRoom(card * owner) : ability( owner, 4) {};


void operationRoom::excute(gameData gameData) 
{
    reriveChosenTeammate(gameData.team[gameData.targetIndex]);
}