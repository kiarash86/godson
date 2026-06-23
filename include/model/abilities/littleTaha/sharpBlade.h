#pragma once
#include <vector>
#include "../ability.h"
class sharpBlade : public ability
{
private:
    card *findTeammateWithLowestHealth(const std::vector<card *> &team);
    void attackChosenEnemy(card *, bool);
    void healChosenTeammate(card *, bool);

public:
    bool excute(gameData gameData) override;

    sharpBlade(card *);
};
