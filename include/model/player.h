#pragma once

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
    player() =default;
    int getHowMuchEnergyHas(){ return howMuchEnergyHas;};
    void setHowMuchEneryHas(const int &energyRound){ howMuchEnergyHas = energyRound;}
    void clearCards();
    void setCards(std::vector<int>);
    const std::vector<card*>& getCards() const { return cards; }

    ~player();
};
