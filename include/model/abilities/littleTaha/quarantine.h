#pragma once
#include <vector>
#include "../ability.h"
class quarantine : public ability
{
private:
    card *findTeammateWithLowestHealth(const std::vector<card *> &team);
    void healChosenTeammate(card *, bool);

public:
    bool excute(gameData gameData) override;

    quarantine(card *);
};
