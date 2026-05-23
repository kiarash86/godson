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
    card(std::string name, int health, int howManyRound);
    ~card();
};
