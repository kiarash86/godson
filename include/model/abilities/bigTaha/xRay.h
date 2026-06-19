#include <vector>
#include "ability.h"
class xRay : public ability
{
private:
    card *owner;
    void attackChosenEnemy(card *);
    void hideMyself();

    public : 
    bool excute(gameData gameData) override;
    xRay(card *);
    ~xRay();
};
