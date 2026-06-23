#pragma once
#include <vector>
#include "../ability.h"
class volley : public ability
{
private:
    void attackAllEnemy(std::vector<card *> &);

    public : 
    bool excute(gameData gameData) override;

    volley(card *);
};
