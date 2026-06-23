#include"include/controller/gameManager.h"
#include <ncurses.h>
int main()
{
    initscr();
    keypad(stdscr, TRUE);
    gameManager * gManager = new gameManager;


    while (true)
    {

      if (gManager->whereToGoFromMainMenu() ==-1)
      {
        break;
      }
        
        
    }
    

    endwin();
}
