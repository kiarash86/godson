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

void elephantKiller::attackChosenEnemy(card *enemy)
{
    if (enemy != nullptr)
    {
        enemy->damage(static_cast<int>(30 * owner->getBuffDmg()));
    }
}

void elephantKiller::healChosenEnemy(card *enemy)
{
    if (enemy != nullptr)
    {
        enemy->heal(static_cast<int>(30 * owner->getBuffDmg()));
    }
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
        healChosenEnemy(gameData.enemy[gameData.targetIndex]);
        healChosenEnemy(who);
    }
    else
    {
        attackChosenEnemy(who);
        attackChosenEnemy(gameData.enemy[gameData.targetIndex]);
    }

    return true;
}
