#pragma once

#include <vector>
#include "../ability.h"
#include"../../gameData.h"
class lastBullet : public ability
{
private:
    void attackChosenEnemy(card *);
    void healChosenEnemy(card *);

public:
    bool excute(gameData gameData) override;
    lastBullet(card *);
};