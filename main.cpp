#include "include/controller/gameManager.h"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

int main()
{
    initscr();
    keypad(stdscr, TRUE);
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    auto *gManager = new gameManager;

    while (true)
    {
      if (gManager->whereToGoFromMainMenu() == -1)
      {
        break;
      }
    }

    delete gManager;
    endwin();
}
