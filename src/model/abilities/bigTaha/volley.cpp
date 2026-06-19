#include "../../../include/model/abilities/bigTaha/volley.h"

void volley::attackAllEnemy(std::vector<card *> &enemy)
{
    for (auto &card : enemy)
    {
        card->damage(30 * owner->getBuffDmg());
        
    }
    
}

volley::volley(card *owner) : ability(owner, 3) {};

void volley::excute(gameData gameData)
{
    attackAllEnemy(gameData.enemy);
}