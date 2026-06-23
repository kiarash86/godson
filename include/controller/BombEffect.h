#pragma once
#include "observerEffect.h"

class BombEffect : public observerEffect
{
private:
    float dmgBuff{1.f};

public:
    BombEffect(card *onWho, float dmgBuff)
        : observerEffect(onWho, 2), dmgBuff(dmgBuff) {}

    void finishedAllRoundNeeded(bool &reverseWorld) override
    {
        if (onWho == nullptr)
        {
            return;
        }

        if (onWho->getHealth() <= (dmgBuff * 360))
        {
            onWho->dmgWithBomb((360 * dmgBuff));
            return;
        }

        if (reverseWorld)
        {
            onWho->heal((200 * dmgBuff));
        }
        else
        {
            onWho->damage((200 * dmgBuff));
        }
    }
};
