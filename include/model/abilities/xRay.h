#include <vector>
#include "ability.h"
class xRay : public ability
{
private:
    card *owner;
    void attackChosenEnemy(card *);
    void hideMyself();

    public : void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex) override;

    xRay(card *);
    ~xRay();
};
