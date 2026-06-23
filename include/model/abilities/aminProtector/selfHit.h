#pragma once
#include <vector>
#include "../ability.h"
class selfHit : public ability
{
private:
    card *chooseRandomTeammate(const std::vector<card *> &team);
    void attackChosenTeammate(card *, bool);
    void healmyself(bool);    
    void healChosenTeammate(card *, bool);
    void attackmyself(bool);

    public : 
    bool excute(gameData gameData) override;

    selfHit(card *);
};
