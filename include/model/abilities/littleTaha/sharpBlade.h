#include <vector>
#include "ability.h"
class sharpBlade : public ability
{
private:
    card *owner;
    card *findTeammateWithLowestHealth(const std::vector<card *> &team);
    void attackChosenEnemy(card *);
    void healChosenTeammate(card *);

public:
    void excute(gameData gameData) override;

    sharpBlade(card *);
    ~sharpBlade();
};
