#include "../../../include/model/abilities/littleTaha/quarantine.h"

card *quarantine::findTeammateWithLowestHealth(const std::vector<card *> &team)
{
    card *who = team.front();
    for (const auto &crd : team)
    {
        if (who->getHealth() < crd->getHealth())
        {
            who = crd;
        }

        // TODO
        // when health are equel what happens?
    }
    return who;
}

void quarantine::healChosenTeammate(card *teammate)
{
    teammate->heal(200);
}

quarantine::quarantine(card *owner) : ability(owner, 4) {};

void quarantine::excute(gameData gameData)
{
    healChosenTeammate(findTeammateWithLowestHealth(gameData.team));
}