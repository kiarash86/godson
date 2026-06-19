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
    return (health<=0);
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

void card::dmgWithBomb(const int& dmg)
{
    health = (health - dmg < 0) ? 0: health - dmg;
    //dmg with buff or without buff?
    //in the observer we use this func
    //TODO
}
void card::heal(const int& heal)
{
    health = (health + heal > maxHealth) ? maxHealth: health + heal;
}