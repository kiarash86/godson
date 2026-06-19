#include "../../../include/model/abilities/littleTaha/sharpBlade.h"


card* sharpBlade::findTeammateWithLowestHealth(const std::vector<card *> &team)
{
    
    card *who;
    
    for (const auto &crd : team)
    {
        
        if (crd->isDead())
        {
            continue;
        }
        who = crd;
        break;
    }

    for (const auto &crd : team)
    {
        if (crd->isDead())
        {
            continue;
        }
        
        if (who->getHealth()> crd->getHealth())
        {
            who = crd;
        }
        
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

sharpBlade::sharpBlade(card *owner) : ability(owner, 2) {};

void sharpBlade::excute(gameData gameData)
{
    attackChosenEnemy(gameData.enemy[gameData.targetIndex]);
    healChosenTeammate(findTeammateWithLowestHealth(gameData.team));
}