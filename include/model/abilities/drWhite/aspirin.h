#pragma once
#include <vector>
#include "../ability.h"
class aspirin : public ability
{
private:
    card *chooseRandomTeammate(const std::vector<card *> &team);
    void attackChosenEnemy(card *);
    void healChosenTeammate(card *);


public:
    bool excute(gameData gameData) override;

    aspirin(card *);    
};
