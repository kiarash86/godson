#include <vector>
#include "ability.h"
class doping : public ability
{
private:
    card *owner;

public:
    void excute(gameData gameData) override;
    doping(card *);

};
