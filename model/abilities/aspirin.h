#include "../cards/card.h"
#include "ability.h"
class aspirin : public ability
{
private:
    void attack();
    void heal();
    card * teammate;
    card * enemy;
    int buff;
public:
     aspirin(card & teammate , card &enemy , int buff) : teammate(teammate) , enemy(enemy) , buff(buff);
    ~aspirin();
};



void aspirin::excute() override {
    attack();
    heal();

}
void aspirin::attack();
{
    enemy->damage(40 * buff);
}

void aspirin::heal();
{
    teammate->heal(40);
}