#include "observerEffect.h"
class healEffect : public observerEffect
{
private:

int healAmount{};
public:
    // we use the buff of the time that bombed on target
    healEffect(card *onWho , int healAmount , int howManyRound) : observerEffect(onWho, howManyRound) , healAmount(healAmount)  {};
    ~healEffect();
    void finishedAllRoundNeeded() override
    {
        return;
    }
    void turnEnded()
    {
        howManyRound--;
        if (onWho->isDead())
        {
            return;
        }
        
        onWho->heal(healAmount);
    }
};

//buff should be taken when someone is dead or no?
//TODO
