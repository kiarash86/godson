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
    card(const std::string &,const int &,const int& ,const std::string &);
    ~card();0
    void addRound();
    void damage(const int&);
    void heal(const int&);
    bool isDead();

};
