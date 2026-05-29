#include "../../../include/model/abilities/bloodSerum.h"

bloodSerum::bloodSerum(card *owner) : ability(owner, 4) {};

void bloodSerum::excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex)
{
    Team[tagetIndex]->setBuffHeal(40, 2);
}