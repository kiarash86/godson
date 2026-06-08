#include"include/controller/gameManager.h"
#include <ncurses.h>
int main()
{
    initscr();
    system("chcp 65001");
    system("cls");
    gameManager * gManager = new gameManager;

    gManager->whereToGoFromMainMenu();

    endwin();
}
