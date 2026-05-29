#include <string>
class card
{
protected:
std::string name{};
int howManyRoundNeededForSpecialPower{};
int health{};
int maxHealth{};
std::pair<float , int> buffDmg = {1 , 15};
std::pair<int , int> buffHeal = {0 , 15};
std::pair<int , int> buffShield = {0 , 0};
//can be stacked buff dmgs??? i mean 2 times 1.2 or reset to 1.2?
//TODO

std::string type;
//func specialAbility

public:
    card(const std::string &name, const int &health, const int &howManyRound, const std::string &type) : name(name), health(health), maxHealth(health), howManyRoundNeededForSpecialPower(howManyRound) , type(type) {};
    ~card();
    void addRound();
    void damage(const int&);
    void heal(const int&);
    bool isDead();

    int getHealth() const{ return health;};
    int getBuffDmg() const{ return buffDmg.first;};
    void setBuffDmg(const int &buff , const int &howManyRound){buffDmg = {buff , howManyRound};};
    int getBuffHeal() const{ return buffHeal.first;};
    void setBuffHeal(const int &buff , const int &howManyRound){buffHeal = {buff , howManyRound};};
    int getBuffShield() const{ return buffShield.first;};
    void setBuffShield(const int &buff , const int &howManyRound){buffShield = {buff , howManyRound};};
};
