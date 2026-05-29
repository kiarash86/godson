#include <vector>
#include "ability.h"
class volley : public ability
{
private:
    card *owner;
    void attackAllEnemy(std::vector<card *> &);

    public : 
    void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex) override;

    volley(card *);
    ~volley();
};
