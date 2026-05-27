#include <string>
class card
{
protected:
std::string name{};
int howManyRoundNeededForSpecialPower{};
int health{};
int maxHealth{};
std::string type;
//func specialAbility

public:
    card(const std::string &name, const int &health, const int &howManyRound, const std::string &type) : name(name), health(health), maxHealth(health), howManyRoundNeededForSpecialPower(howManyRound) , type(type) {};
    ~card();
    void addRound();
    void damage(const int&);
    void heal(const int&);
    bool isDead();

};
