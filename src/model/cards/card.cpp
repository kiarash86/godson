#include "../../../include/model/cards/card.h"
#include "../../../include/model/abilities/ability.h"

card::~card()
{
    for (ability *ab : abilities)
    {
        delete ab;
    }
    abilities.clear();
}

void card::addAbility(ability *ab)
{
    if (ab != nullptr)
    {
        abilities.push_back(ab);
    }
}

ability *card::getAbility(size_t index) const
{
    if (index >= abilities.size())
    {
        return nullptr;
    }
    return abilities[index];
}

void card::addRound()
{
    if (buffDmgRounds > 0)
    {
        --buffDmgRounds;
        if (buffDmgRounds == 0)
        {
            buffDmg = 1.f;
        }
    }

    if (buffShieldRounds > 0)
    {
        --buffShieldRounds;
        if (buffShieldRounds == 0)
        {
            buffShield = 0;
        }
    }

    if (hidden > 0)
    {
        --hidden;
    }
}

bool card::canBeKilledWithThisShot(const int dmg) const
{
    return dmg >= buffShield + health;
}

bool card::isDead() const
{
    return health <= 0;
}

void card::damage(const int &dmg)
{
    if (dmg <= 0)
    {
        return;
    }

    if (buffShield > 0)
    {
        if (buffShield >= dmg)
        {
            buffShield -= dmg;
            return;
        }

        int leftDmg = dmg - buffShield;
        buffShield = 0;
        health = std::max(0, health - leftDmg);
        return;
    }

    health = std::max(0, health - dmg);
}

void card::dmgWithBomb(const int &dmg)
{
    health = std::max(0, health - dmg);
}

void card::heal(const int &healAmount)
{
    if (healAmount <= 0)
    {
        return;
    }
    health = std::min(maxHealth, health + healAmount);
}

bool card::canUseSpecialPower(const int roundNumber) const
{
    const ability *specialAbility = getAbility(2);
    return specialAbility != nullptr && specialAbility->canBeExcuted(roundNumber);
}

int card::getSpecialRoundsLeft(const int roundNumber) const
{
    const ability *specialAbility = getAbility(2);
    return specialAbility == nullptr ? 0 : specialAbility->getRoundsLeft(roundNumber);
}

void card::markSpecialPowerUsed(const int roundNumber)
{
    ability *specialAbility = getAbility(2);
    if (specialAbility != nullptr)
    {
        specialAbility->setLastRoundNumberUsed(roundNumber);
    }
}
