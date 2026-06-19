//add a obersever class for this
//TODO
// if die with bomb what happens to your shield?
#include "../../../include/model/abilities/bigTaha/brotherRevenge.h"
card *brotherRevenge::chooseRandomEnemy(const std::vector<card *> &enemy)
{
    int who;
    do
    {
        who = rand() % enemy.size();
    } while (enemy[who]->isDead());
    return enemy[who];
}

void brotherRevenge::bombingChosenEnemy(card *enemy)
{
    //TODO
    //create observer here i think
}

brotherRevenge::brotherRevenge(card *owner) : ability(owner, 3) {};

void brotherRevenge::excute(gameData gameData)
{
    gameData.effects.push_back(new BombEffect{gameData.enemy[gameData.targetIndex]  , owner->getBuffDmg()});
}