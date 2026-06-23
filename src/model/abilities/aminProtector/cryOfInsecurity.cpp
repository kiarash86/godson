#include "../../../../include/model/abilities/aminProtector/cryOfInsecurity.h"

card *cryOfInsecurity::chooseRandomEnemy(const std::vector<card *> &enemy)
{
    std::vector<card *> validEnemy;
    for (const auto &crd : enemy)
    {
        if (crd == nullptr || crd->isDead() || crd->IsHidden())
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

void cryOfInsecurity::attackMyTeammates(std::vector<card *> &Team, bool reverseWorld)
{

    for (auto &crd : Team)
    {
        if (crd == owner)
        {
            continue;
        }

        applyDamage(crd, static_cast<int>(30 * owner->getBuffDmg()), reverseWorld);
    }
}

void cryOfInsecurity::healMyTeammates(std::vector<card *> &Team, bool reverseWorld)
{

    for (auto &crd : Team)
    {
        if (crd == owner)
        {
            continue;
        }
        applyHealing(crd, static_cast<int>(30 * owner->getBuffDmg()), reverseWorld);
    }
}

void cryOfInsecurity::healChosenEnemy(card *enemy, bool reverseWorld)
{
    applyHealing(enemy, static_cast<int>(250 * owner->getBuffDmg()), reverseWorld);
}


void cryOfInsecurity::attackChosenEnemy(card *enemy, bool reverseWorld)
{
    applyDamage(enemy, static_cast<int>(250 * owner->getBuffDmg()), reverseWorld);
}


cryOfInsecurity::cryOfInsecurity(card *owner) : ability(owner, "cryOfInsecurity", 4, 3, false, false, false, true) {}

bool cryOfInsecurity::excute(gameData gameData)
{

    card *randomEnemy = chooseRandomEnemy(gameData.enemy);
    if (randomEnemy == nullptr)
    {
        return false;
    }
    if (gameData.reverseWorld)
    {

        healChosenEnemy(randomEnemy, gameData.reverseWorld);
        healMyTeammates(gameData.team, gameData.reverseWorld);
    }
    else
    {
        attackChosenEnemy(randomEnemy, gameData.reverseWorld);
        attackMyTeammates(gameData.team, gameData.reverseWorld);
    }
    setLastRoundNumberUsed(gameData.round);
    return true;
}
