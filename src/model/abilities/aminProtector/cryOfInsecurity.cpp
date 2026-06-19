#include "../../../include/model/abilities/aminProtector/cryOfInsecurity.h"

card *cryOfInsecurity::chooseRandomEnemy(const std::vector<card *> &enemy)
{
    int who;
    do
    {
        who = rand() % enemy.size();
    } while (enemy[who]->isDead());
    return enemy[who];
}
void cryOfInsecurity::attackMyTeammates(std::vector<card *> &Team)
{
    for (auto &crd : Team)
    {
        if (crd == owner)
        {
            continue;
        }
        crd->damage(30 *owner->getBuffDmg());

        
    }
    
    // adding buff to this dmg or no?
    // TODO
}

void cryOfInsecurity::attackChosenEnemy(card *enemy)
{
    enemy->damage(250 * owner->getBuffDmg());
}

cryOfInsecurity::cryOfInsecurity(card *owner) : ability(owner, 4) {};

void cryOfInsecurity::excute(gameData gameData)
{
    attackChosenEnemy(chooseRandomEnemy(gameData.enemy));
    attackMyTeammates(gameData.team);
}