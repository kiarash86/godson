#pragma once
#include "../cards/card.h"
#include "../gameData.h"
#include "controller/observerEffect.h"

#include <algorithm>
#include <string>
#include <utility>

class ability
{
protected:
    std::string label;
    int energyCost{};
    int howManyRoundNeeded{};
    int lastroundNumberUsed{0};
    bool needsTarget{false};
    bool targetIsAlly{false};
    bool allowDeadTarget{false};
    bool specialPower{false};
    card *owner{};

    ability(card *owner, std::string label, int energyCost, int howManyRoundNeeded = 0,
            bool needsTarget = false, bool targetIsAlly = false, bool allowDeadTarget = false,
            bool specialPower = false)
        : label(std::move(label)), energyCost(energyCost), howManyRoundNeeded(howManyRoundNeeded),
          needsTarget(needsTarget), targetIsAlly(targetIsAlly), allowDeadTarget(allowDeadTarget),
          specialPower(specialPower), owner(owner) {}

protected:
    void applyDamage(card *target, int amount, bool reverseWorld) const
    {
        if (target == nullptr || amount <= 0)
        {
            return;
        }

        if (reverseWorld)
        {
            target->heal(amount);
        }
        else
        {
            target->damage(amount);
        }
    }

    void applyHealing(card *target, int amount, bool reverseWorld) const
    {
        if (target == nullptr || amount <= 0)
        {
            return;
        }

        if (reverseWorld)
        {
            target->damage(amount);
        }
        else
        {
            target->heal(amount);
        }
    }

public:
    virtual ~ability() = default;
    virtual bool excute(gameData gameData) = 0;

    const std::string &getLabel() const { return label; }
    int getEneryCost() const { return energyCost; }
    bool requiresTarget() const { return needsTarget; }
    bool targetIsTeamMate() const { return targetIsAlly; }
    bool canTargetDead() const { return allowDeadTarget; }
    bool isSpecialPower() const { return specialPower; }
    bool canBeExcuted(const int &roundNumber) const
    {
        return (roundNumber - howManyRoundNeeded >= lastroundNumberUsed);
    }
    int getRoundsLeft(const int &roundNumber) const
    {
        return std::max(0, howManyRoundNeeded - (roundNumber - lastroundNumberUsed));
    }
    void setLastRoundNumberUsed(const int &lastRoundNumber)
    {
        lastroundNumberUsed = lastRoundNumber;
    }
};