#include "../../../include/model/abilities/doping.h"



doping::doping(card *owner) : ability(owner, 4) {};

void doping::excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex) 
{
    Team[tagetIndex]->setBuffDmg(1.2 ,2);
}