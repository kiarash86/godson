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

void cryOfInsecurity::attackMyTeammates(std::vector<card *> &Team)
{

    for (auto &crd : Team)
    {
        if (crd == owner)
        {
            continue;
        }

        crd->damage(static_cast<int>(30 * owner->getBuffDmg()));
    }
}

void cryOfInsecurity::healMyTeammates(std::vector<card *> &Team)
{

    for (auto &crd : Team)
    {
        if (crd == owner)
        {
            continue;
        }
        crd->heal(static_cast<int>(30 * owner->getBuffDmg()));
    }
}

void cryOfInsecurity::healChosenEnemy(card *enemy)
{
    if (enemy != nullptr)
    {
        enemy->heal(static_cast<int>(250 * owner->getBuffDmg()));
    }
}


void cryOfInsecurity::attackChosenEnemy(card *enemy)
{
    if (enemy != nullptr)
    {
        enemy->damage(static_cast<int>(250 * owner->getBuffDmg()));
    }
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

        healChosenEnemy(randomEnemy);
        healMyTeammates(gameData.team);
    }
    else
    {
        attackChosenEnemy(randomEnemy);
        attackMyTeammates(gameData.team);
    }
    setLastRoundNumberUsed(gameData.round);
    return true;
}
