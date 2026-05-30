#include"include/controller/gameManager.h"
int main()
{
    system("chcp 65001");
    system("cls");
    gameManager * gManager = new gameManager;

    gManager->whereToGoFromMainMenu();
}
