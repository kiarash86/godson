#include "../cards/card.h"
class ability
{
    protected:
     int energyCost;
        card *owner;
        ability(int energyCost) : energyCost(energyCost){};
        ~ability() = default;
        virtual void excute(std::vector<card *>& Team, std::vector<card *> &enemy, int tagetIndex = -1)
        = 0;
};

