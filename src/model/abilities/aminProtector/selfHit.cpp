#include "../../../include/model/abilities/aminProtector/selfHit.h"

card *selfHit::chooseRandomTeammate(const std::vector<card *> &team)
{
    int who;
    do
    {
        who = rand() % team.size();
    } while (team[who]->isDead());
    return team[who];
}
void selfHit::attackChosenTeammate(card *teammate)
{
    teammate->damage(25);
    //adding buff to this dmg or no?
    //TODO
}
void selfHit::healmyself()
{
    owner->heal(75);
}

selfHit::selfHit(card *owner) : ability(owner, 3) {};

void selfHit::excute(gameData gameData)
{
    attackChosenTeammate(chooseRandomTeammate(gameData.team));
    healmyself();
}