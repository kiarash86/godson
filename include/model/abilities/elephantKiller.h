#include <vector>
#include "ability.h"
class elephantKiller : public ability
{
private:
    card *owner;
    card *findEnemyeWithhighestHealth(const std::vector<card *> &team);
    void attackChosenEnemy(card *);
public:
    void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex) override;

    elephantKiller(card *);
    ~elephantKiller();
};
