#include "../../../include/model/abilities/danyGo/elephantKiller.h"

card *elephantKiller::findEnemyeWithhighestHealth(const std::vector<card *> &enemy)
{
    //TODO
    //check for being alive or not if its not then choose another one
    card *who;
    
    for (const auto &crd : enemy)
    {
        
        if (crd->isDead() or crd->IsHidden())
        {
            continue;
        }
        
        who = crd;
        break;

    }
    
    for (const auto &crd : enemy)
    {
        if (crd->isDead() or crd->IsHidden())
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



void elephantKiller::healChosenEnemy(card *enemy)
{
    enemy->heal(30 * owner->getBuffDmg());
}


elephantKiller::elephantKiller(card *owner) : ability(owner, 4) {};

bool elephantKiller::excute(gameData gameData)
{
    card* who =findEnemyeWithhighestHealth(gameData.enemy);
    if (who =nullptr)
    {
        return false;
    }
    
    if (gameData.reverseWorld)
    {
        //reverse in order?
        healChosenEnemy(gameData.enemy[gameData.targetIndex]);
        healChosenEnemy(findEnemyeWithhighestHealth(gameData.enemy));
        
    }
    else{
        
        attackChosenEnemy(findEnemyeWithhighestHealth(gameData.enemy));
        attackChosenEnemy(gameData.enemy[gameData.targetIndex]);
    }
    
    return true;
}