#include <vector>
#include "ability.h"
class doping : public ability
{
private:
    card *owner;

public:
    void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex) override;
    doping(card *);

};
