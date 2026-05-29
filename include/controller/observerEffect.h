#include "../model/cards/card.h"
class observerEffect
{
protected:
    int howManyRound{};
    card *onWho;
    void turnEnded()
    {
        howManyRound--;
        if (howManyRound == 0)
        {
            finishedAllRoundNeeded();
        }
    }
    virtual void finishedAllRoundNeeded() = 0;
    virtual ~observerEffect() = 0;
    observerEffect(card *&onWho, int howManyRound) : onWho(onWho), howManyRound(howManyRound) {};
};
