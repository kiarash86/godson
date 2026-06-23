#include "../../../../include/model/abilities/danyGo/hooked.h"

void hooked::attackChosenEnemy(card *enemy, bool reverseWorld)
{
    if (enemy != nullptr)
    {
        applyDamage(enemy, static_cast<int>(20 * owner->getBuffDmg() * getFactorOfBuffDmg(enemy)), reverseWorld);
    }
}

void hooked::healChosenEnemy(card *enemy, bool reverseWorld)
{
    if (enemy != nullptr)
    {
        applyHealing(enemy, static_cast<int>(20 * owner->getBuffDmg() / getFactorOfBuffDmg(enemy)), reverseWorld);
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
        healChosenEnemy(gameData.enemy[gameData.targetIndex], gameData.reverseWorld);
    }
    else
    {
        attackChosenEnemy(gameData.enemy[gameData.targetIndex], gameData.reverseWorld);
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
