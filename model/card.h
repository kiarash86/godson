#include <string>
class card
{

protected:
std::string name{};
int howManyRoundNeededForSpecialPower{};
int health{};
//pair<func> abilities;
//func specialAbility

public:
    card(const std::string &,const int &,const int&);
    ~card();
    void addRound();

    
};
