#include "card.h"

card::card(const std::string& name ,const int& health,const  int& howManyRound ) : name(name) , health(health) , maxHealth(health) ,  howManyRoundNeededForSpecialPower(howManyRound) {}

card::~card()
{
}

void card::addRound()
{
    howManyRoundNeededForSpecialPower++;
}

card& card::operator+=(int heal)
{
    this->health += heal;
    return *this;
}
card& card::operator-=(int dmg)
{
    this->health -=dmg;
    return *this;
}