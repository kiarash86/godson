#include "../../../../include/model/abilities/danyGo/elephantKiller.h"

card *elephantKiller::findEnemyeWithhighestHealth(const std::vector<card *> &enemy)
{
    card *who = nullptr;

    for (const auto &crd : enemy)
    {
        if (crd == nullptr || crd->isDead() || crd->IsHidden())
        {
            continue;
        }

        if (who == nullptr || who->getHealth() < crd->getHealth())
        {
            who = crd;
        }
    }
    return who;
}

void elephantKiller::attackChosenEnemy(card *enemy, bool reverseWorld)
{
    applyDamage(enemy, static_cast<int>(30 * owner->getBuffDmg()), reverseWorld);
}

void elephantKiller::healChosenEnemy(card *enemy, bool reverseWorld)
{
    applyHealing(enemy, static_cast<int>(30 * owner->getBuffDmg()), reverseWorld);
}


elephantKiller::elephantKiller(card *owner) : ability(owner, "elephantKiller", 4, 0, true, false, false, false) {}

bool elephantKiller::excute(gameData gameData)
{
    if (gameData.enemy.empty() || gameData.targetIndex < 0 || gameData.targetIndex >= static_cast<int>(gameData.enemy.size()))
    {
        return false;
    }

    card *who = findEnemyeWithhighestHealth(gameData.enemy);
    if (who == nullptr || gameData.enemy[gameData.targetIndex] == nullptr)
    {
        return false;
    }

    if (gameData.reverseWorld)
    {
        healChosenEnemy(gameData.enemy[gameData.targetIndex], gameData.reverseWorld);
        healChosenEnemy(who, gameData.reverseWorld);
    }
    else
    {
        attackChosenEnemy(who, gameData.reverseWorld);
        attackChosenEnemy(gameData.enemy[gameData.targetIndex], gameData.reverseWorld);
    }

    return true;
}
