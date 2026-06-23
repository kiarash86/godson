#pragma once
#include <iostream>
#include "showMenuForChoosingcards.h"

std::vector<int> ShowSelectCardsMenuOption()
{
    return selectThreeCards("HEROES",
                            {"LITTLE TAHA",
                             "BIG TAHA",
                             "DR.WHITE",
                             "DANY GO",
                             "AMIN PROTECTOR"});
}
