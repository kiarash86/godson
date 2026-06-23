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

void selfHit::attackChosenTeammate(card *teammate)
{
    if (teammate != nullptr)
    {
        teammate->damage(25);
    }
}

void selfHit::healChosenTeammate(card *teammate)
{
    if (teammate != nullptr)
    {
        teammate->heal(25);
    }
}

void selfHit::healmyself()
{
    owner->heal(75);
}

void selfHit::attackmyself()
{
    owner->damage(75);
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
        healChosenTeammate(teammate);
        attackmyself();
    }
    else
    {
        attackChosenTeammate(teammate);
        healmyself();
    }
    return true;
}
