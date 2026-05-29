#include "../../../include/model/cards/card.h"


void card::addRound()
{
    howManyRoundNeededForSpecialPower++;
}


bool card::isDead()
{
    return health;
}

void card::damage( int& dmg)
{
    if (buffShield.first!=0 and buffShield.second!=0)
    {
        if (buffShield.first > dmg)
        {
            buffShield.first -= dmg;
            dmg =0 ;
        }
        else {
            dmg -=buffShield.first;
            buffShield.first =0 ;
        }
    }
    health = (health - dmg < 0) ? 0: health - dmg;
}
void card::heal(const int& heal)
{
    health = (health + heal > maxHealth) ? maxHealth: health + heal;
}
