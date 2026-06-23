#include "../../../../include/model/abilities/littleTaha/bloodSerum.h"

bloodSerum::bloodSerum(card *owner) : ability(owner, "bloodSerum", 4, 0, false, false, false, false) {}

card *bloodSerum::findTeammateWithLowestHealth(const std::vector<card *> &team)
{
    card *who = nullptr;

    for (const auto &crd : team)
    {
        if (crd == nullptr || crd->isDead())
        {
            continue;
        }

        if (who == nullptr || who->getHealth() > crd->getHealth())
        {
            who = crd;
        }
    }

    return who;
}

bool bloodSerum::excute(gameData gameData)
{
    card *target = findTeammateWithLowestHealth(gameData.team);
    if (target == nullptr)
    {
        return false;
    }

    gameData.effects.push_back(new healEffect{target, 40, 2});
    return true;
}
