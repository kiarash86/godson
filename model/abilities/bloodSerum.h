#include "../cards/card.h"
#include "ability.h"
class bloodSerum : public ability
{
private:
    void addBuff();
    card *teammate;
    card *enemy;


public:
    bloodSerum(card &teammate, card &enemy) : teammate(teammate), enemy(enemy);
    ~bloodSerum();
};

void bloodSerum::excute() override
{
    addBuff();
}
void doping::addBuff()
{
    teammate->buff = {40, 2 , 1};
}