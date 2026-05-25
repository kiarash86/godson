#include "../cards/card.h"
#include "ability.h"
class sharpBlade : public ability
{
private:
    void attack();
    void heal();
    card *teammate;
    card *enemy;
    int buff;

public:
    sharpBlade(card &teammate, card &enemy, int buff) : teammate(teammate), enemy(enemy), buff(buff);
    ~sharpBlade();
};


void sharpBlade::attack();
{
    enemy->damage(30 * buff);
}

void sharpBlade::heal();
{
    teammate->heal(40);
}
void sharpBlade::excute() override
{
    attack();
}