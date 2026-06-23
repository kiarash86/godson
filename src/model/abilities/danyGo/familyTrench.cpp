#include "../../../../include/model/abilities/danyGo/familyTrench.h"

familyTrench::familyTrench(card *owner) : ability(owner, "familyTrench", 4, 4, false, false, false, true) {}

bool familyTrench::excute(gameData gameData)
{
    card *target = findTeammateWithLowestHealth(gameData.team);
    if (target == nullptr)
    {
        return false;
    }

    gameData.effects.push_back(new shieldEffect{target, 250, 2});
    return true;
}

card *familyTrench::findTeammateWithLowestHealth(const std::vector<card *> &team)
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
