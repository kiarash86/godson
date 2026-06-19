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


void selfHit::healChosenTeammate(card *teammate)
{
    teammate->heal(25);

}
//note
// i didnt use buff for this 2 funcs
//its not hard to add it but this ability with using buff is so weak

void selfHit::healmyself()
{
    owner->heal(75);
}



void selfHit::attackmyself()
{
    owner->damage(75);
}

selfHit::selfHit(card *owner) : ability(owner, 3) {};

bool selfHit::excute(gameData gameData)
{
    if (gameData.reverseWorld)
    {
        healChosenTeammate(chooseRandomTeammate(gameData.team));
        attackmyself();
        
    }
    else
    {
        attackChosenTeammate(chooseRandomTeammate(gameData.team));
        healmyself();

    }
}