#include "../../../../include/model/abilities/drWhite/aspirin.h"
#include <cstdlib>

card *aspirin::chooseRandomTeammate(const std::vector<card *> &team)
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

void aspirin::attackChosenEnemy(card *enemy, bool reverseWorld)
{
    applyDamage(enemy, static_cast<int>(40 * owner->getBuffDmg()), reverseWorld);
}

void aspirin::healChosenTeammate(card *teammate, bool reverseWorld)
{
    applyHealing(teammate, 40, reverseWorld);
}

aspirin::aspirin(card *owner) : ability(owner, "aspirin", 3, 0, true, false, false, false) {}

bool aspirin::excute(gameData gameData)
{
    if (gameData.enemy.empty() || gameData.targetIndex < 0 || gameData.targetIndex >= static_cast<int>(gameData.enemy.size()))
    {
        return false;
    }

    attackChosenEnemy(gameData.enemy[gameData.targetIndex], gameData.reverseWorld);
    healChosenTeammate(chooseRandomTeammate(gameData.team), gameData.reverseWorld);
    return true;
}
