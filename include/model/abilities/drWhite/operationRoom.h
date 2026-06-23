#pragma once
#include <vector>
#include "../ability.h"
class operationRoom : public ability
{
private:

    void reriveChosenTeammate(card *);

public:
    bool excute(gameData gameData) override;
    operationRoom(card *);
};
