#pragma once
#include <algorithm>
#include <string>
#include <vector>

class ability;

class card
{
protected:
    std::string name{};
    int howManyRoundNeededForSpecialPower{};
    int health{};
    int hidden{};

    float buffDmg{1.f};
    int buffDmgRounds{0};

    int buffShield{0};
    int buffShieldRounds{0};

    int lastSpecialRoundUsed{0};

    std::string type;
    std::vector<ability *> abilities;

public:
    const int maxHealth{};

    card(const std::string &name, const int &health, const int &howManyRound, const std::string &type)
        : name(name), howManyRoundNeededForSpecialPower(howManyRound), health(health), type(type), maxHealth(health) {}
    virtual ~card();

    void addAbility(ability *ab);
    const std::vector<ability *> &getAbilities() const { return abilities; }
    ability *getAbility(size_t index) const;

    void dmgWithBomb(const int &);
    void addRound();
    void damage(const int &);
    void heal(const int &);
    bool isDead() const;
    bool canBeKilledWithThisShot(const int) const;

    int getHealth() const { return health; }
    float getBuffDmg() const { return buffDmg; }
    void setBuffDmg(float buff, int howManyRound)
    {
        buffDmg = buff;
        buffDmgRounds = howManyRound;
    }
    void increaseBuffDmg(float buff) { buffDmg *= buff; }
    void decreaseBuffDmg(float buff)
    {
        if (buff <= 0.f)
        {
            return;
        }
        buffDmg /= buff;
    }

    int getBuffShield() const { return buffShield; }
    void setBuffShield(int buff, int howManyRound)
    {
        buffShield = buff;
        buffShieldRounds = howManyRound;
    }
    void increaseBuffShield(int buff) { buffShield += buff; }
    void decreaseBuffShield(int buff)
    {
        if (buff >= buffShield)
        {
            buffShield = 0;
            return;
        }
        buffShield -= buff;
    }

    bool IsHidden() const { return hidden > 0; }
    void increaseHiddenTime(int buff) { hidden += buff; }
    void decreaseHiddenTime(int buff = 1)
    {
        hidden = std::max(0, hidden - buff);
    }

    bool canUseSpecialPower(const int roundNumber) const;
    int getSpecialRoundsLeft(const int roundNumber) const;
    void markSpecialPowerUsed(const int roundNumber);

    const std::string &getName() const { return name; }
    const std::string &getType() const { return type; }
    int getSpecialCooldown() const { return howManyRoundNeededForSpecialPower; }
};
