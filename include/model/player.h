#include"cards/card.h"
#include"cards/bigTaha.h"
#include"cards/littleTaha.h"
#include"cards/danyGo.h"
#include"cards/drWhite.h"
#include"cards/protectorAmin.h"

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
    void setCards(std::vector<int>);
    std::vector<card*> getCards(){return cards;}

    ~player();
};

player::player()
{
    
}

player::~player()
{
}
