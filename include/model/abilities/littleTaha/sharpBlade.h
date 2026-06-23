#pragma once
#include <vector>
#include "../ability.h"
class sharpBlade : public ability
{
private:
    card *findTeammateWithLowestHealth(const std::vector<card *> &team);
    void attackChosenEnemy(card *);
    void healChosenTeammate(card *);

public:
    bool excute(gameData gameData) override;

    sharpBlade(card *);
};
