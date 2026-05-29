#include "../../model/abilities/aspirin.h"

card *aspirin::chooseRandomTeammate(const std::vector<card*> & team)
{
    int who;
    do
    {
        who = rand()% team.size();
    } while ( team[who]->isDead() );
    return team[who];
}
void aspirin::attackChosenEnemy(card *enemy)
{
    enemy->damage(40 * owner->getBuffDmg());
}
void aspirin::healChosenTeammate(card * teammate)
{
    teammate->heal(40);
}

aspirin::aspirin(card *owner) : ability( owner, 3) {};

void aspirin::excute(std::vector<card *>& Team, std::vector<card *>& enemy, int tagetIndex) 
{
    attackChosenEnemy(enemy[tagetIndex]);
    healChosenTeammate(chooseRandomTeammate(Team));
}