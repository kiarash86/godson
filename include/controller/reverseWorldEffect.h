#pragma once
#include "observerEffect.h"

class reverseWorldEffect : public observerEffect
{
public:
    reverseWorldEffect(card *onWho, int howManyRound)
        : observerEffect(onWho, howManyRound) {}

    void finishedAllRoundNeeded(bool &reverseWorld) override
    {
        reverseWorld = !reverseWorld;
    }
};
