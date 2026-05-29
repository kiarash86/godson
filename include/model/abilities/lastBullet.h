#include <vector>
#include "ability.h"
class lastBullet : public ability
{
private:
    card *owner;
    void attackChosenEnemy(card *);

public:
    void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex) override;

    lastBullet(card *);
    ~lastBullet();
};
