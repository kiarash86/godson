#pragma once
#include "observerEffect.h"

class shieldEffect : public observerEffect
{
private:
    int shieldAmount{};

public:
    shieldEffect(card *onWho, int shieldAmount, int howManyRound)
        : observerEffect(onWho, howManyRound), shieldAmount(shieldAmount)
    {
        if (onWho != nullptr)
        {
            onWho->increaseBuffShield(shieldAmount);
        }
    }

    ~shieldEffect() override = default;

    void finishedAllRoundNeeded(bool &reverseWorld) override
    {
        if (onWho != nullptr)
        {
            onWho->decreaseBuffShield(shieldAmount);
        }
    }
};
