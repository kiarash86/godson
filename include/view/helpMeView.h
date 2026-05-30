#pragma once
#include <iostream>
#include "showMenuWithKey.h"

int ShowHelpMeMenuOption()
{
    return viewInteractiveMenu("HELP!!!", {"HOW TO PLAY", "ABOUT GAME", "BACK TO MENU"});
}
