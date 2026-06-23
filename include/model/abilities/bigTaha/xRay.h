#pragma once
#include <vector>
#include "../ability.h"
class xRay : public ability
{
private:
    void attackChosenEnemy(card *);
    void hideMyself();

    public : 
    bool excute(gameData gameData) override;
    xRay(card *);
};
