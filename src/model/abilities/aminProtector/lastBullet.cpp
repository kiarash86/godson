#include "../../../../include/model/abilities/aminProtector/lastBullet.h"

void lastBullet::attackChosenEnemy(card *enemy)
{
    if (enemy != nullptr)
    {
        if (enemy->canBeKilledWithThisShot(static_cast<int>(55 * owner->getBuffDmg() * 2)))
        {
            enemy->damage(static_cast<int>(55 * owner->getBuffDmg() * 2));
            return;
        }
        enemy->damage(static_cast<int>(55 * owner->getBuffDmg()));
    }
}

void lastBullet::healChosenEnemy(card *enemy)
{
    if (enemy != nullptr)
    {
        if (enemy->getHealth() + static_cast<int>(55 * owner->getBuffDmg() * 2) >= enemy->maxHealth)
        {
            enemy->heal(static_cast<int>(55 * owner->getBuffDmg() * 2));
            return;
        }
        enemy->heal(static_cast<int>(55 * owner->getBuffDmg()));
    }
}

bool lastBullet::excute(gameData gameData)
{
    if (gameData.enemy.empty() || gameData.targetIndex < 0 || gameData.targetIndex >= static_cast<int>(gameData.enemy.size()))
    {
        return false;
    }

    if (gameData.reverseWorld)
    {
        healChosenEnemy(gameData.enemy[gameData.targetIndex]);
    }
    else
    {
        attackChosenEnemy(gameData.enemy[gameData.targetIndex]);
    }
    return true;
}

lastBullet::lastBullet(card *owner) : ability(owner, "lastBullet", 3, 0, true, false, false, false) {}
