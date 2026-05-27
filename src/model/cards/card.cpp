#include "../../../include/model/cards/card.h"


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
    health = (health - dmg < 0) ? 0: health - dmg;
}
void card::heal(const int& heal)
{
    health = (health + heal > maxHealth) ? maxHealth: health + heal;
}
