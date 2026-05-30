#include "../../../include/model/abilities/bloodSerum.h"

bloodSerum::bloodSerum(card *owner) : ability(owner, 4) {};

void bloodSerum::excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex, std::vector<observerEffect *> &effects)
{
    effects.push_back(new healEffect{Team[tagetIndex] , 40 , 2});
}