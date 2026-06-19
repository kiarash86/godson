#include <vector>
#include "ability.h"
class cryOfInsecurity : public ability
{
private:
    card *owner;
    card *chooseRandomEnemy(const std::vector<card *> &team);
    void attackMyTeammates(std::vector<card *> &);
    void attackChosenEnemy(card *enemy);

    public : void excute(gameData gameData) override;

    cryOfInsecurity(card *);
    ~cryOfInsecurity();
};
