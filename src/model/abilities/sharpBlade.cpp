#include "../../../include/model/abilities/sharpBlade.h"

card *sharpBlade::findTeammateWithLowestHealth(const std::vector<card *> &team)
{
    card* who= team.front();
    for (const auto &crd : team)
    {
        if (who->getHealth()< crd->getHealth())
        {
            who = crd;
        }
        
        //TODO
        //when health are equel what happens?
    }
    return who;

}
void sharpBlade::attackChosenEnemy(card *enemy)
{
    enemy->damage(30 * owner->getBuffDmg());
}
void sharpBlade::healChosenTeammate(card *teammate)
{
    teammate->heal(20);
}

sharpBlade::sharpBlade(card *owner) : ability(owner, 3) {};

void sharpBlade::excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex)
{
    attackChosenEnemy(enemy[tagetIndex]);
    healChosenTeammate(findTeammateWithLowestHealth(Team));
}