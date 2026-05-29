#include "../../../include/model/abilities/volley.h"

void volley::attackAllEnemy(std::vector<card *> &enemy)
{
    for (auto &card : enemy)
    {
        card->damage(30 * owner->getBuffDmg());
        
    }
    
}

volley::volley(card *owner) : ability(owner, 3) {};

void volley::excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex)
{
    attackAllEnemy(enemy);
}