#include "../cards/card.h"
#include "ability.h"
class elephantKiller : public ability
{
private:
    void attack(card &enemy);
    card *enemy1;
    card *enemy2;
    int buff;

public:
    elephantKiller(card &enemy1, card &enem2, int buff) : enemy2(enemy2), enemy2(enemy2), buff(buff);
    ~elephantKiller();
};

void elephantKiller::attack(card &enemy);
{
    enemy->damage(50 * buff);
}

void elephantKiller::excute() override {
    attack(enemy1);
    attack(enemy2);
}
