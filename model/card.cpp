#include "card.h"

card::card(const std::string &name, const int &health, const int &howManyRound, , const std::string &type) : name(name), health(health), maxHealth(health), howManyRoundNeededForSpecialPower(howManyRound) , type(type) {}

card::~card()
{
}

void card::addRound()
{
    howManyRoundNeededForSpecialPower++;
}

card& card::operator+=(int heal)
{
    this->health = (this->health + heal > maxHealth) ? maxHealth , this->health +heal;
    return *this;
}
card& card::operator-=(int dmg)
{
    this->health -=dmg;
    this->health = (this->health - dmg < 0) ? 0 , this->health -dmg;
    return *this;
}
bool card::isDead()
{
    return health;
}
