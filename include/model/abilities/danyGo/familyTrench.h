#include <vector>
#include "ability.h"
#include "../../controller/shieldEffect.h"

class familyTrench : public ability
{
private:
    card *owner;
    card *findTeammateWithLowestHealth(const std::vector<card *> &team);

public:
    bool excute(gameData gameData) override;
    familyTrench(card *);
};
