#include <vector>
#include "ability.h"
class bloodSerum : public ability
{
private:
    card *owner;

public:
    void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex) override;
    bloodSerum(card *);
};
