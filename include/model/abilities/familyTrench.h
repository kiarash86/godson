#include <vector>
#include "ability.h"
#include "../../controller/shieldEffect.h"

class familyTrench : public ability
{
private:
    card *owner;
    card *findTeammateWithLowestHealth(const std::vector<card *> &team);

public:
    void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex, std::vector<observerEffect *> &effects) override;
    familyTrench(card *);
};
