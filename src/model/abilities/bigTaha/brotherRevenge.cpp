#include "../../../../include/model/abilities/bigTaha/brotherRevenge.h"

card *brotherRevenge::chooseRandomEnemy(const std::vector<card *> &enemy)
{
    std::vector<card *> validEnemy;
    for (const auto &crd : enemy)
    {
        if (crd == nullptr || crd->isDead())
        {
            continue;
        }
        validEnemy.push_back(crd);
    }

    if (validEnemy.empty())
    {
        return nullptr;
    }

    return validEnemy[(rand() % validEnemy.size())];
}

brotherRevenge::brotherRevenge(card *owner) : ability(owner, "brotherRevenge", 3, 4, false, false, false, true) {}

bool brotherRevenge::excute(gameData gameData)
{
    card *target = chooseRandomEnemy(gameData.enemy);
    if (target == nullptr)
    {
        return false;
    }

    gameData.effects.push_back(new BombEffect{target, owner->getBuffDmg()});
    return true;
}
