#pragma once
#include <vector>
#include "../ability.h"
class doping : public ability
{
private:

public:
    bool excute(gameData gameData) override;
    doping(card *);

};
