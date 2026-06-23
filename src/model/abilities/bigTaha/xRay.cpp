#include "../../../../include/model/abilities/bigTaha/xRay.h"

void xRay::attackChosenEnemy(card *enemy)
{
    if (enemy != nullptr)
    {
        enemy->damage(static_cast<int>(90 * owner->getBuffDmg()));
    }
}

xRay::xRay(card *owner) : ability(owner, "xRay", 4, 0, true, false, false, false) {}

void xRay::hideMyself()
{
    owner->increaseHiddenTime(1);
}

bool xRay::excute(gameData gameData)
{
    if (gameData.enemy.empty() || gameData.targetIndex < 0 || gameData.targetIndex >= static_cast<int>(gameData.enemy.size()))
    {
        return false;
    }

    attackChosenEnemy(gameData.enemy[gameData.targetIndex]);
    hideMyself();
    return true;
}
