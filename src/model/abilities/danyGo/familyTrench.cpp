#include "../../../include/model/abilities/danyGo/familyTrench.h"

familyTrench::familyTrench(card *owner) : ability(owner, 4) {};

bool familyTrench::excute(gameData gameData)
{
    gameData.effects.push_back(new shieldEffect{findTeammateWithLowestHealth(gameData.team) , 250 , 3});
    return true;
}

card *familyTrench::findTeammateWithLowestHealth(const std::vector<card *> &team)
{

    card *who;

    for (const auto &crd : team)
    {

        if (crd->isDead())
        {
            continue;
        }
        who = crd;
        break;
    }

    for (const auto &crd : team)
    {
        if (crd->isDead())
        {
            continue;
        }

        if (who->getHealth() > crd->getHealth())
        {
            who = crd;
        }

    }
    return who;
}
