#include "../../../../include/model/abilities/danyGo/hooked.h"

void hooked::attackChosenEnemy(card *enemy)
{
    if (enemy != nullptr)
    {
        enemy->damage(static_cast<int>(20 * owner->getBuffDmg() * getFactorOfBuffDmg(enemy)));
    }
}

void hooked::healChosenEnemy(card *enemy)
{
    if (enemy != nullptr)
    {
        enemy->heal(static_cast<int>(20 * owner->getBuffDmg() / getFactorOfBuffDmg(enemy)));
    }
}

hooked::hooked(card *owner) : ability(owner, "hooked", 2, 0, true, false, false, false) {}

bool hooked::excute(gameData gameData)
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
    setNewLastAttackedCard(gameData.enemy[gameData.targetIndex]);
    return true;
}

float hooked::getFactorOfBuffDmg(card *enemyCard)
{
    if (lastAttackedCardBuffDmg.first == nullptr)
    {
        return 1.f;
    }

    if (lastAttackedCardBuffDmg.first == enemyCard)
    {
        return lastAttackedCardBuffDmg.second;
    }

    return 1.f;
}

void hooked::setNewLastAttackedCard(card *enemy)
{
    if (enemy == lastAttackedCardBuffDmg.first)
    {
        lastAttackedCardBuffDmg.second *= 1.6f;
    }
    else
    {
        lastAttackedCardBuffDmg.first = enemy;
        lastAttackedCardBuffDmg.second = 1.6f;
    }
}
