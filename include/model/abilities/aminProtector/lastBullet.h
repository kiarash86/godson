#include <vector>
#include "ability.h"
#include"../gameData.h"
class lastBullet : public ability
{
private:
    card *owner;
    void attackChosenEnemy(card *);
    void healChosenEnemy(card *);

public:
    bool excute(gameData gameData) override;
    lastBullet(card *);
};