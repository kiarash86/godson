#pragma once
#include<random>
#include <vector>
#include "../ability.h"
class cryOfInsecurity : public ability
{
private:
    card *chooseRandomEnemy(const std::vector<card *>& );
    void attackMyTeammates(std::vector<card *> &, bool);
    void attackChosenEnemy(card *, bool);    
    void healMyTeammates(std::vector<card *> &, bool);
    void healChosenEnemy(card *, bool);

public: 
    bool excute(gameData) override;
    
    cryOfInsecurity(card *);
}; 
