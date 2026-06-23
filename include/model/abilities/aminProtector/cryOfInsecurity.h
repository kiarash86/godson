#pragma once
#include<random>
#include <vector>
#include "../ability.h"
class cryOfInsecurity : public ability
{
private:
    card *chooseRandomEnemy(const std::vector<card *>& );
    void attackMyTeammates(std::vector<card *> &);
    void attackChosenEnemy(card *);    
    void healMyTeammates(std::vector<card *> &);
    void healChosenEnemy(card *);

public: 
    bool excute(gameData) override;
    
    cryOfInsecurity(card *);
}; 
