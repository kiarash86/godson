#include <string>
class card
{

protected:
std::string name{};
int howManyRoundNeededForSpecialPower{};
int health{};
int maxHealth{};
//pair<func> abilities;
//func specialAbility

public:
    card(const std::string &,const int &,const int&);
    ~card();
    void addRound();
    card &operator+=(int);
    card &operator-=(int);
    bool isDead();

};
