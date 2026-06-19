#include"include/controller/gameManager.h"
#include <ncurses.h>
int main()
{
    initscr();
    system("chcp 65001");
    system("cls");
    keypad(stdscr, TRUE);
    gameManager * gManager = new gameManager;


    while (true)
    {

        gManager->whereToGoFromMainMenu();
        
    }
    

    endwin();
}
