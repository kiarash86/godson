#include "../cards/card.h"
#include "ability.h"
class selfHit : public ability
{
private:
    void heal();
    void getHealthFromTeammate();
    card *teammate;
    card * myself
    int buff;

public:
    selfHit(card &myself  ,card &teammate) : myself(myself) teammate(teammate);
    ~selfHit();
};

void selfHit::excute() override
{
    getHealthFromTeammate();
    heal();
}
void selfHit::getHealthFromTeammate();
{
    teammate->dmg(25);
}

void selfHit::heal();
{
    myself-> heal(75);
}