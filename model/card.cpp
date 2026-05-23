#include "card.h"

card::card(const std::string& name ,const int& health,const  int& howManyRound ) : name(name) , health(health) ,  howManyRoundNeededForSpecialPower(howManyRound) {}

card::~card()
{
}

void card::addRound()
{
    howManyRoundNeededForSpecialPower++;
}
