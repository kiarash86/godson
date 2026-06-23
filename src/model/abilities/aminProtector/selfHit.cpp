#include "../../../../include/model/abilities/aminProtector/selfHit.h"
#include <cstdlib>

card *selfHit::chooseRandomTeammate(const std::vector<card *> &team)
{
    std::vector<card *> validTeam;
    for (const auto &crd : team)
    {
        if (crd == nullptr || crd->isDead())
        {
            continue;
        }
        validTeam.push_back(crd);
    }

    if (validTeam.empty())
    {
        return nullptr;
    }

    return validTeam[(rand() % validTeam.size())];
}

void selfHit::attackChosenTeammate(card *teammate, bool reverseWorld)
{
    applyDamage(teammate, 25, reverseWorld);
}

void selfHit::healChosenTeammate(card *teammate, bool reverseWorld)
{
    applyHealing(teammate, 25, reverseWorld);
}

void selfHit::healmyself(bool reverseWorld)
{
    applyHealing(owner, 75, reverseWorld);
}

void selfHit::attackmyself(bool reverseWorld)
{
    applyDamage(owner, 75, reverseWorld);
}

selfHit::selfHit(card *owner) : ability(owner, "selfHit", 3, 0, false, false, false, false) {}

bool selfHit::excute(gameData gameData)
{
    card *teammate = chooseRandomTeammate(gameData.team);
    if (teammate == nullptr)
    {
        return false;
    }

    if (gameData.reverseWorld)
    {
        healChosenTeammate(teammate, gameData.reverseWorld);
        attackmyself(gameData.reverseWorld);
    }
    else
    {
        attackChosenTeammate(teammate, gameData.reverseWorld);
        healmyself(gameData.reverseWorld);
    }
    return true;
}
