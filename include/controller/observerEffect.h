#include "../model/cards/card.h"
class observerEffect
{
    public:
        bool isFinished() const
        {
            return !howManyRound;
        }

protected:

    int howManyRound{};
    card *onWho;
   virtual void turnEnded()
    {
        howManyRound--;
    }
    virtual void finishedAllRoundNeeded() = 0;
    virtual ~observerEffect() = 0;
    observerEffect(card *&onWho, int howManyRound) : onWho(onWho), howManyRound(howManyRound) {};
};
