#include <vector>
#include "ability.h"
class operationRoom : public ability
{
private:
    card *owner;

    void reriveChosenTeammate(card *);

public:
    void excute(gameData gameData) override;
    operationRoom(card *);
    ~operationRoom();
};
