#include "../../../include/model/abilities/familyTrench.h"

familyTrench::familyTrench(card *owner) : ability(owner, 4) {};

void familyTrench::excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex, std::vector<observerEffect *> &effects)
{
    effects.push_back(new shieldEffect{findTeammateWithLowestHealth(Team) , 250 , 3});
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

        // TODO
        // when health are equel what happens?
    }
    return who;
}
