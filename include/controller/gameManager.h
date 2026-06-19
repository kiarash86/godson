#include "../view/battleMap.h"
#include "../view/helpMeOptions.h"
#include "../view/helpMeView.h"
#include "../view/preparationGameView.h"
#include "../view/startView.h"
#include "../view/storitesMenu.h"
#include "../view/storyShow.h"
#include "model/player.h"

class gameManager {
private:
  player player1;
  player player2;

public:
  void whereToGoFromStoriesMenu() {
    int index;
    while (true) {
      index = ShowStoriesMenuOption();
      if (index == 7) {
        break;
      }

      handleStoriesMenu(index);
    }
  }

  void whereToGoFromHelpMenu() {
    int index;
    while (true) {
      index = ShowHelpMeMenuOption();
      if (index == 2) {
        break;
      }

      handleOptionsMenu(index);
    }

    // TODO
    // should be fixed later because of stacking func in func
    whereToGoFromMainMenu();
  }

  void whereToGoFromMainMenu() {
    int index;
    index = ShowStartMenuOption();
    switch (index) {
    case 0:
      ShowSelectCardsMenuOption();
      ShowSelectCardsMenuOption();

      break;
    case 1:
      whereToGoFromHelpMenu();
      break;
    case 2:
      whereToGoFromStoriesMenu();
      break;
    case 3:
      exit(0);
      break;
    }
  }
};