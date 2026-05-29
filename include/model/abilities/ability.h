#include "../cards/card.h"
class ability
{
    protected:
     int energyCost;
        card *owner;
        ability(card * owner , int energyCost) : energyCost(energyCost) , owner(owner){};
        ~ability() = default;
        virtual void excute(std::vector<card *>& Team, std::vector<card *> &enemy, int tagetIndex = -1)
        = 0;
};

