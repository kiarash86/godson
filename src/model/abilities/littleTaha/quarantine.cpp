#include "../../../../include/model/abilities/littleTaha/quarantine.h"

card *quarantine::findTeammateWithLowestHealth(const std::vector<card *> &team)
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

void quarantine::healChosenTeammate(card *teammate, bool reverseWorld)
{
    applyHealing(teammate, 200, reverseWorld);
}

quarantine::quarantine(card *owner) : ability(owner, "quarantine", 4, 3, false, false, false, true) {}

bool quarantine::excute(gameData gameData)
{
    card *who = findTeammateWithLowestHealth(gameData.team);
    if (who == nullptr)
    {
        return false;
    }

    healChosenTeammate(who, gameData.reverseWorld);
    return true;
}
