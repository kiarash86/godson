#include "../../../include/model/abilities/xRay.h"

void xRay::attackChosenEnemy(card *enemy)
{

    enemy->damage(90 * owner->getBuffDmg());
}

xRay::xRay(card *owner) : ability(owner, 4) {};

void xRay::hideMyself()
{
    owner->increaseHiddenTime(1);
}
void xRay::excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex)
{
    attackChosenEnemy(enemy[tagetIndex]);
    hideMyself();
}