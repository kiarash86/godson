#include <string>
class card
{
protected:
    std::string name{};
    int howManyRoundNeededForSpecialPower{};
    int health{};
    int maxHealth{};
    int hidden{};

    int buffDmg{1};
    int buffShield{0};
    // can be stacked buff dmgs??? i mean 2 times 1.2 or reset to 1.2?
    // TODO

    std::string type;
    // func specialAbility

public:
    card(const std::string &name, const int &health, const int &howManyRound, const std::string &type) : name(name), health(health), maxHealth(health), howManyRoundNeededForSpecialPower(howManyRound), type(type) {};
    ~card();
    void dmgWithBomb(const int &);
    void addRound();
    void damage(const int &);
    void heal(const int &);
    bool isDead();
    bool canBeKilledWithThisShot(const int);
    int getHealth() const { return health; };
    int getBuffDmg() const { return buffDmg; };
    void increaseBuffDmg(const int &buff) { buffDmg *= buff; };
    void decreaseBuffDmg(const int &buff) { buffDmg /= buff; };
    int getBuffShield() const { return buffShield; };
    void increaseBuffShield(const int &buff) { buffShield += buff; };
    void decreaseBuffShield(const int &buff)
    {
        if (buff >= buffShield)
        {
            buffShield = 0;
            return;
        }
        buffShield -= buff;
    };
    bool IsHidden() const { return hidden; };
    void increaseHiddenTime(const int &buff) { hidden += buff; };
};
