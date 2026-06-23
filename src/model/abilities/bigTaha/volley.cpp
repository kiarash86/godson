#include "../../../../include/model/abilities/bigTaha/volley.h"

void volley::attackAllEnemy(std::vector<card *> &enemy, bool reverseWorld)
{
    for (auto &card : enemy)
    {
        if (card == nullptr || card->isDead())
        {
            continue;
        }
        applyDamage(card, static_cast<int>(30 * owner->getBuffDmg()), reverseWorld);
    }
}

volley::volley(card *owner) : ability(owner, "volley", 3, 0, false, false, false, false) {}

bool volley::excute(gameData gameData)
{
    attackAllEnemy(gameData.enemy, gameData.reverseWorld);
    return true;
}
