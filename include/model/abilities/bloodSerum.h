#include <vector>
#include "ability.h"
#include "../../controller/healEffect.h"
class bloodSerum : public ability
{
private:
    card *owner;

public:
    void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex, std::vector<observerEffect *> &effects) override;
    bloodSerum(card *);
};
