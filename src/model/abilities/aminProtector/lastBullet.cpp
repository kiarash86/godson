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

lastBullet::lastBullet(card *owner) : ability(owner, 3) {};

void lastBullet::excute(gameData gameData)
{

    if (gameData.reserveWorld)
    {
        
    }
    else
    {
        
    }
    attackChosenEnemy(gameData.enemy[gameData.targetIndex]);
}