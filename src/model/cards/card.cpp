#include "../../../include/model/cards/card.h"


void card::addRound()
{
    howManyRoundNeededForSpecialPower++;
}
bool card::canBeKilledWithThisShot(const int dmg)
{
    if (dmg >= buffShield.first + health)
    {
        return true;
    }
    return false;
}

bool card::isDead()
{
    return health;
}

void card::damage(const int& dmg)
{
    if (buffShield.first!=0 and buffShield.second!=0)
    {
        if (buffShield.first > dmg)
        {
            buffShield.first -= dmg;
            return;
        }
        else {

            health = (health - (dmg - buffShield.first) < 0) ? 0 : health - (dmg - buffShield.first);
            buffShield.first =0 ;
            return;
        }
    }
    
    health = (health - dmg < 0) ? 0: health - dmg;
}
void card::heal(const int& heal)
{
    health = (health + heal > maxHealth) ? maxHealth: health + heal;
}
