#include <vector>
#include "ability.h"
class selfHit : public ability
{
private:
    card *owner;
    card *chooseRandomTeammate(const std::vector<card *> &team);
    void attackChosenTeammate(card *);
    void healmyself();

    public : void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex) override;

    selfHit(card *);
    ~selfHit();
};
