#include "../../../include/model/abilities/aminProtector/lastBullet.h"

void lastBullet::attackChosenEnemy(card *enemy)
{
    if (enemy->canBeKilledWithThisShot(55 * owner->getBuffDmg()*2))
    {
        enemy->damage(55 * owner->getBuffDmg() *2);
        return;
    }
    enemy->damage(55 * owner->getBuffDmg());
    
}

void lastBullet::healChosenEnemy(card *enemy)
{
    if (enemy->getHealth() +(55 * owner->getBuffDmg()*2) >= enemy->maxHealth)
    {
        enemy->heal(55 * owner->getBuffDmg() *2);
        return;
    }
    enemy->heal(55 * owner->getBuffDmg());
    
}

bool lastBullet::excute(gameData gameData)
{
    
    if (gameData.reverseWorld)
    {
        healChosenEnemy(gameData.enemy[gameData.targetIndex]);
    }
    else
    {
        attackChosenEnemy(gameData.enemy[gameData.targetIndex]);
        
    }
}

lastBullet::lastBullet(card *owner) : ability(owner, 3) {};