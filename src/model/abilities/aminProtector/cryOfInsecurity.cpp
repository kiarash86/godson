#include "../../../include/model/abilities/aminProtector/cryOfInsecurity.h"

card *cryOfInsecurity::chooseRandomEnemy(const std::vector<card *> &enemy)
{
    std::vector<card *> validEnemy;
    for (const auto &crd : enemy)
    {
        if (crd->isDead() or crd->IsHidden())
        {
            continue;
        }
        validEnemy.push_back(crd);
    }
    if (validEnemy.size() == 0)
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

        crd->damage(30 * owner->getBuffDmg());
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
        crd->heal(30 * owner->getBuffDmg());
    }
}

void cryOfInsecurity::healChosenEnemy(card *enemy)
{
    enemy->heal(250 * owner->getBuffDmg());
}

cryOfInsecurity::cryOfInsecurity(card *owner) : ability(owner, 4 , 3) {};

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