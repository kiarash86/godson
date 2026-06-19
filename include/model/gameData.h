#include "../cards/card.h"
#include<vector>
struct gameData
{
    std::vector<card *> team;
    std::vector<card *> enemy;
    int targetIndex =-1;
    std::vector<observerEffect*> &effects;
    int round;
    bool reverseWorld;
};

