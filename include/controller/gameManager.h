#include "../view/battleMap.h"
#include "../view/helpMeOptions.h"
#include "../view/helpMeView.h"
#include "../view/preparationGameView.h"
#include "../view/startView.h"
#include "../view/storitesMenu.h"
#include "../view/storyShow.h"
#include "model/player.h"
#include "observerEffect.h"
class gameManager {
private:
  player player1;
  player player2;
  std::vector<observerEffect> effects;
  int round{1};
  bool reverseWorld{false};

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
  }

  int whereToGoFromMainMenu() {
    int index;
    index = ShowStartMenuOption();
    switch (index) {
    case 0:
      player1.setCards(ShowSelectCardsMenuOption());
      player2.setCards(ShowSelectCardsMenuOption());

      Battle();
      break;
    case 1:
      whereToGoFromHelpMenu();
      break;
    case 2:
      whereToGoFromStoriesMenu();
      break;
    case 3:
      return -1;
      break;
    }
    return 0;
  }

  void Battle() {
    std::string currentLog = "The battle has begun! Choose your action.";

    while (true) {

      // effect controller
      for (size_t i = 0; i < effects.size(); i++) {

        effects[i].turnEnded(reverseWorld);
        if (effects[i].isFinished()) {
          effects[i].finishedAllRoundNeeded(reverseWorld);
          effects.erase(effects.begin() + i);
        }
      }
      //


      draw(player1, player2, round, round % 2, " ");

      round++;
    }
  }
};