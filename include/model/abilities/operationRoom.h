#include <vector>
#include "ability.h"
class aspirin : public ability
{
private:
    card *owner;

    void reriveChosenTeammate(card *);

public:
    void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex) ;
    aspirin(card *);
    ~aspirin();
};
