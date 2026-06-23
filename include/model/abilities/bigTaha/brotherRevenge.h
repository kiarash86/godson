#pragma once
#include <vector>
#include "../ability.h"
#include "../../../controller/BombEffect.h"
class brotherRevenge : public ability
{
private:
    card *chooseRandomEnemy(const std::vector<card *> &team);
    void bombingChosenEnemy(card *enemy);

public:
    bool excute(gameData gameData) override;
    
    brotherRevenge(card *);
};
