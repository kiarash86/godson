#include "../cards/card.h"
#include "../gameData.h"
#include "../../controller/observerEffect.h"
class ability
{
protected:
    int energyCost;
    int howManyRoundNeeded;
    int lastroundNumberUsed{0};
    card *owner;
    ability(card * owner , int energyCost , int howManyRoundNeeded = 0) : energyCost(energyCost) , owner(owner) , howManyRoundNeeded(howManyRoundNeeded){};
    ~ability() = default;
    virtual bool excute(gameData gameData)
        = 0;

public:
int getEneryCost(){return energyCost;}
    bool canBeExcuted(const int& roundNumber){ return (roundNumber-howManyRoundNeeded >= lastroundNumberUsed);}
    void setLastRoundNumberUsed(const int & lastRoundNumber){ lastroundNumberUsed = lastRoundNumber;}

    
};

