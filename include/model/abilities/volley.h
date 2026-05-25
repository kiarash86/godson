#include "../cards/card.h"
#include "ability.h"
class volley : public ability
{
private:
    void attack();
    card *enemy1;
    card *enemy2;
    card *enemy3;
    int buff;

public:
    volley(, int buff, card &enemy1, card &enemy2 = NULL, card &enemy3 = NULL) : enemy1(enemy1), enemy2(enemy2), enemy3(enemy3), buff(buff);
    ~volley();
};

void volley::attack(card* enemy);
{
    enemy->damage(30 * buff);
}


void volley::excute() override
{
    attack(enemy1);
    attack(enemy2);
    attack(enemy3);
}