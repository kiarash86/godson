#include "../cards/card.h"
#include "ability.h"
class lastBullet : public ability
{
private:
    bool couldBeKilled();

    card *enemy;
    card *myself;

public:
    lastBullet(card & myself card &enemy) : myself(myself)  enemy(enemy);
    ~lastBullet();
};

void lastBullet::excute() override
{
    if (couldBeKilled())
    {
        enemy->dmg(myself->buff * 55 * 2);
    }
    else 
    {
        enemy->dmg(myself->buff * 55 );
    }
    
}
bool doping::couldBeKilled()
{
    return (myself->buff * 55 * 2 >= enemy->health)
}