#include <iostream>
#include"showMenuWithKey.h"

    int ShowStartMenuOption()
    {
        return viewInteractiveMenu("MENU", {
          "start new game"
        , "help me"
        , "story of cards"
        , "exit" });
    }
