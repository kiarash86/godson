#include <vector>
#include "ability.h"
class operationRoom : public ability
{
private:
    card *owner;

    void reriveChosenTeammate(card *);

public:
    void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex) override;
    operationRoom(card *);
    ~operationRoom();
};
