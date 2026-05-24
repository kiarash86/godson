#include "card.h"

card::card(const std::string &name, const int &health, const int &howManyRound, , const std::string &type) : name(name), health(health), maxHealth(health), howManyRoundNeededForSpecialPower(howManyRound) , type(type) {}

card::~card()
{
}

void card::addRound()
{
    howManyRoundNeededForSpecialPower++;
}


bool card::isDead()
{
    return health;
}

void card::damage(const int& dmg)
{
    health = (health - dmg < 0) ? 0, health - dmg;
}
void card::heal(const int& heal)
{
    health = (health + heal > maxHealth) ? maxHealth, health + heal
}
