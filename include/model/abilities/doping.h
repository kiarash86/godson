#include "../cards/card.h"
#include "ability.h"
class doping: public ability
{
private:
    card *teammate;
void addBuff();

    public : doping(card &teammate) : teammate(teammate);
    ~doping();
};

void doping::addBuff()
{
teammate -> buff = {1.2 , 2 , 0};
}
void doping::excute() override{
    addBuff();
}