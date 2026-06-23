#pragma once
#include "observerEffect.h"

class healEffect : public observerEffect
{
private:
    int healAmount{};

public:
    healEffect(card *onWho, int healAmount, int howManyRound)
        : observerEffect(onWho, howManyRound), healAmount(healAmount) {}

    void turnEnded(bool &reverseWorld) override
    {
        --howManyRound;
        if (onWho == nullptr || onWho->isDead())
        {
            return;
        }

        if (reverseWorld)
        {
            onWho->damage(healAmount);
        }
        else
        {
            onWho->heal(healAmount);
        }
    }
};