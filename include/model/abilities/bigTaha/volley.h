#include <vector>
#include "ability.h"
class volley : public ability
{
private:
    card *owner;
    void attackAllEnemy(std::vector<card *> &);

    public : 
    void excute(gameData gameData) override;

    volley(card *);
    ~volley();
};
