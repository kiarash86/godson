#include "../cards/card.h"
#include "../gameData.h"
#include "../../controller/observerEffect.h"
class ability
{
    protected:
     int energyCost;
        card *owner;
        ability(card * owner , int energyCost) : energyCost(energyCost) , owner(owner){};
        ~ability() = default;
        virtual void excute(gameData gameData)
        = 0;
};

