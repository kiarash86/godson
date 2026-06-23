#pragma once
#include <vector>
#include "../ability.h"
#include "../../../controller/healEffect.h"
class bloodSerum : public ability
{
private:
    card *findTeammateWithLowestHealth(const std::vector<card *> &team);

public:
    bool excute(gameData gameData) override;
    bloodSerum(card *);
};
