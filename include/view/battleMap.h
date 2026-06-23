#pragma once
#include "../model/cards/card.h"
#include "../model/player.h"
#include <ncurses.h>
#include <string>
#include <vector>

inline void draw(player p1, player p2, int roundCount, int currentTurn,
                 const std::string &actionLog) {

  clear();
  curs_set(0);

  printw(
      "====================================================================\n");
  printw("                             ARENA                          \n");
  printw(
      "               ROUND: %d  |  CURRENT TURN: PLAYER %d                \n",
      roundCount, currentTurn);
  printw("===================================================================="
         "\n\n");

  printw("[ PLAYER 2 TEAM ]\n");
  printw(
      "--------------------------------------------------------------------\n");
  for (size_t i = 0; i < p2.getCards().size(); ++i) {
    if (p2.getCards()[i]->isDead()) {
      printw(" [%d] Hero: DEFEATED\n", i + 1);
    } else {
      printw(" [%d] Hero | HP: %3d | Damage Buff: %.1f\n", i + 1,
             p2.getCards()[i]->getHealth(), p2.getCards()[i]->getBuffDmg());
    }
  }
  printw("--------------------------------------------------------------------"
         "\n\n");

  printw("                      vs ( COMBAT ZONE )                      \n\n");

  printw("[ PLAYER 1 TEAM ]\n");
  printw(
      "--------------------------------------------------------------------\n");
  for (size_t i = 0; i < p1.getCards().size(); ++i) {
    if (p1.getCards()[i]->isDead()) {
      printw(" [%d] Hero: DEFEATED\n", i + 1);
    } else {
      printw(" [%d] Hero | HP: %3d | Damage Buff: %.1f\n", i + 1,
             p1.getCards()[i]->getHealth(), p1.getCards()[i]->getBuffDmg());
    }
  }
  printw("--------------------------------------------------------------------"
         "\n\n");

  printw(
      "=========================== ACTION LOG =============================\n");
  printw(" > %s\n", actionLog.c_str());
  printw(
      "====================================================================\n");

  refresh();
}

inline int getChoice(const std::string &promptMessage, int maxOptions) {
  printw("\n%s (Press 1-%d or 'q' to Quit): ", promptMessage.c_str(),
         maxOptions);
  refresh();

  while (true) {
    int ch = getch();

    if (ch >= '1' && ch < '1' + maxOptions) {
      return ch - '1';
    }
    if (ch == 'q' || ch == 'Q') {
      return -1;
    }
  }
}