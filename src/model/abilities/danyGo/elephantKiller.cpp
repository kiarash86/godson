#include "../../../include/model/abilities/danyGo/elephantKiller.h"

card *elephantKiller::findEnemyeWithhighestHealth(const std::vector<card *> &enemy)
{
    //TODO
    //check for being alive or not if its not then choose another one
    card *who;
    
    for (const auto &crd : enemy)
    {
        
        if (crd->isDead())
        {
            continue;
        }
        
        who = crd;
        break;

    }

    for (const auto &crd : enemy)
    {
        if (crd->isDead())
        {
            continue;
        }
        
        if (who->getHealth() < crd->getHealth())
        {
            who = crd;
        }

    }
    return who;
}
void elephantKiller::attackChosenEnemy(card *enemy)
{
    enemy->damage(30 * owner->getBuffDmg());
}


elephantKiller::elephantKiller(card *owner) : ability(owner, 4) {};

void elephantKiller::excute(gameData gameData)
{
    attackChosenEnemy(gameData.enemy[gameData.targetIndex]);
    attackChosenEnemy(findEnemyeWithhighestHealth(gameData.enemy));
}