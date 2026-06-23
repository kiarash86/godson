#pragma once
#include <vector>
#include "../ability.h"
class elephantKiller : public ability
{
private:
    card *findEnemyeWithhighestHealth(const std::vector<card *> &team);
    void attackChosenEnemy(card *, bool);
    void healChosenEnemy(card *, bool);
public:
    bool excute(gameData gameData) override;

    elephantKiller(card *);
};
