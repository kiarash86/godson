#include <vector>
#include "ability.h"
class elephantKiller : public ability
{
private:
    card *owner;
    card *findEnemyeWithhighestHealth(const std::vector<card *> &team);
    void attackChosenEnemy(card *);
public:
    bool excute(gameData gameData) override;

    elephantKiller(card *);
    ~elephantKiller();
};
