#include <vector>
#include "ability.h"
class xRay : public ability
{
private:
    card *owner;
    void attackChosenEnemy(card *);
    void hideMyself();

    public : void excute(gameData gameData) override;

    xRay(card *);
    ~xRay();
};
