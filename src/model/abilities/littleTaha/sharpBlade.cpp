#include "../../../../include/model/abilities/littleTaha/sharpBlade.h"

card *sharpBlade::findTeammateWithLowestHealth(const std::vector<card *> &team)
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

void sharpBlade::attackChosenEnemy(card *enemy, bool reverseWorld)
{
    applyDamage(enemy, static_cast<int>(30 * owner->getBuffDmg()), reverseWorld);
}

void sharpBlade::healChosenTeammate(card *teammate, bool reverseWorld)
{
    applyHealing(teammate, 20, reverseWorld);
}

sharpBlade::sharpBlade(card *owner) : ability(owner, "sharpBlade", 2, 0, true, false, false, false) {}

bool sharpBlade::excute(gameData gameData)
{
    if (gameData.enemy.empty() || gameData.targetIndex < 0 || gameData.targetIndex >= static_cast<int>(gameData.enemy.size()))
    {
        return false;
    }

    attackChosenEnemy(gameData.enemy[gameData.targetIndex], gameData.reverseWorld);
    healChosenTeammate(findTeammateWithLowestHealth(gameData.team), gameData.reverseWorld);
    return true;
}
