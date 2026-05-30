#include "observerEffect.h"
class shieldEffect : public observerEffect
{
private:
    int shieldAmount{};

public:
    // we use the buff of the time that bombed on target
    shieldEffect(card *onWho, int shieldAmount, int howManyRound) : observerEffect(onWho, howManyRound), shieldAmount(shieldAmount) {
        onWho->increaseBuffShield(shieldAmount);
    };
    ~shieldEffect();
    void finishedAllRoundNeeded() override
    {
        onWho->decreaseBuffShield(shieldAmount);
    }

};
// buff should be taken when someone is dead or no?
// TODO
