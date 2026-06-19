#include <vector>
#include "ability.h"
class lastBullet : public ability
{
private:
    card *owner;
    void attackChosenEnemy(card *);

public:
    void excute(gameData gameData) override;

    lastBullet(card *);
    ~lastBullet();
};
