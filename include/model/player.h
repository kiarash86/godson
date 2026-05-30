#include"cards/card.h"
#include<vector>
class player
{
private:
    std::vector<card *> cards;
    int howMuchEnergyHas{};
public:
    player();
    int getHowMuchEnergyHas(){ return howMuchEnergyHas;};
    int setHowMuchEneryHas(const int &energyRound){ howMuchEnergyHas = energyRound;}

    ~player();
};

player::player()
{
    
}

player::~player()
{
}
