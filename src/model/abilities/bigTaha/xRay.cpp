#include "../../../include/model/abilities/bigTaha/xRay.h"

void xRay::attackChosenEnemy(card *enemy)
{

    enemy->damage(90 * owner->getBuffDmg());
}

xRay::xRay(card *owner) : ability(owner, 4) {};

void xRay::hideMyself()
{
    owner->increaseHiddenTime(1);
}
void xRay::excute(gameData gameData)
{
    attackChosenEnemy(gameData.enemy[gameData.targetIndex]);
    hideMyself();
}