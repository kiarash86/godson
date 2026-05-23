#include <string>
class card
{
protected:
std::string name{};
int howManyRoundNeededForSpecialPower{};
int health{};
int maxHealth{};
std::string type;
//pair<func> abilities;
//func specialAbility

public:
    card(const std::string &,const int &,const int& ,const std::string &);
    ~card();0
    void addRound();
    card &operator+=(int);
    card &operator-=(int);
    bool isDead();

};
