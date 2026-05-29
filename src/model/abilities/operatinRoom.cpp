#include "../../../include/model/abilities/operationRoom.h"


void operationRoom::reriveChosenTeammate(card * teammate)
{
    teammate->heal(200);
    //TODO
    //deleting bads buffs
}
operationRoom::operationRoom(card * owner) : ability( owner, 4) {};


void operationRoom::excute(std::vector<card *>& Team, std::vector<card *>& enemy, int tagetIndex) 
{
    reriveChosenTeammate(Team[tagetIndex]);
}