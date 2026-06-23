#include <iostream>
#include "showMenuWithKey.h"

int ShowStoriesMenuOption()
{
    return viewInteractiveMenu("HEROES", {"LITTLE TAHA", "BIG TAHA", "DR.WHITE" , "DANY GO", "AMIN PROTECTOR" ,"BACK TO MENU"});
}
