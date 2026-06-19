#include "../../../include/model/abilities/danyGo/hooked.h"

void hooked::attackChosenEnemy(card *enemy)
{
    enemy->damage(20 * owner->getBuffDmg() * getFactorOfBuffDmg(enemy));
}


void hooked::healChosenEnemy(card *enemy)
{
    enemy->heal(20 * owner->getBuffDmg() / getFactorOfBuffDmg(enemy));
}

hooked::hooked(card *owner) : ability(owner, 2) {};

bool hooked::excute(gameData gameData)
{
    if (gameData.reverseWorld)
    {
        healChosenEnemy(gameData.enemy[gameData.targetIndex]);
    }
    else
    {
        attackChosenEnemy(gameData.enemy[gameData.targetIndex]);
        
    }
    setNewLastAttackedCard(gameData.enemy[gameData.targetIndex]);
    return true;
}

float hooked::getFactorOfBuffDmg(card *enemyCard)
{
    if (lastAttackedCardBuffDmg.first == nullptr)
    {
        return 1;
    }

    if (lastAttackedCardBuffDmg.first == enemyCard)
    {
        return lastAttackedCardBuffDmg.second;
    }

    return 1;
}

void hooked::setNewLastAttackedCard(card *enemy)
{
    if (enemy == lastAttackedCardBuffDmg.first)
    {
        lastAttackedCardBuffDmg.second *= 1.6;
    }
    else
    {

        lastAttackedCardBuffDmg.first = enemy;
        lastAttackedCardBuffDmg.second = 1.6;
    }
}
