#include "../../../../include/model/abilities/bigTaha/volley.h"

void volley::attackAllEnemy(std::vector<card *> &enemy)
{
    for (auto &card : enemy)
    {
        if (card == nullptr || card->isDead())
        {
            continue;
        }
        card->damage(static_cast<int>(30 * owner->getBuffDmg()));
    }
}

volley::volley(card *owner) : ability(owner, "volley", 3, 0, false, false, false, false) {}

bool volley::excute(gameData gameData)
{
    attackAllEnemy(gameData.enemy);
    return true;
}
