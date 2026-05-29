#include "../../../include/model/abilities/lastBullet.h"

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

void lastBullet::excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex)
{
    attackChosenEnemy(enemy[tagetIndex]);
}