#include <vector>
#include "ability.h"
#include<utility>
class hooked : public ability
{
private:
    card *owner;
    std::pair<card *, float> lastAttackedCardBuffDmg{nullptr , 1};
    void attackChosenEnemy(card *);
    float getFactorOfBuffDmg(card *);
    void setNewLastAttackedCard(card *);
public:
    void excute(gameData gameData) override;

    hooked(card *);
    ~hooked();
};
