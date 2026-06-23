#pragma once
#include <vector>
#include "../ability.h"
class operationRoom : public ability
{
private:

    void reriveChosenTeammate(card *, bool);

public:
    bool excute(gameData gameData) override;
    operationRoom(card *);
};
