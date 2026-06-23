#pragma once
#include "../model/cards/card.h"
#include "../model/player.h"
#include <ncurses.h>
#include <string>
#include <vector>

inline void draw(const player &p1, const player &p2, int roundCount, int currentTurn,
                 int p1Energy, int p2Energy, const std::string &actionLog) {
  clear();
  curs_set(0);

  printw("====================================================================\n");
  printw("                             ARENA                                  \n");
  printw("               ROUND: %d  |  CURRENT TURN: PLAYER %d                \n",
         roundCount, currentTurn);
  printw("====================================================================\n\n");

  printw("[ PLAYER 2 TEAM ]    Energy: %d\n", p2Energy);
  printw("--------------------------------------------------------------------\n");
  for (size_t i = 0; i < p2.getCards().size(); ++i) {
    const card *c = p2.getCards()[i];
    if (c == nullptr) {
      printw(" [%zu] <empty slot>\n", i + 1);
      continue;
    }
    if (c->isDead()) {
      printw(" [%zu] %-16s | DEFEATED\n", i + 1, c->getName().c_str());
    } else {
      printw(" [%zu] %-16s | HP:%4d/%-4d | Shield:%4d | Buff:x%.1f | Hidden:%s | Special:%s\n",
             i + 1, c->getName().c_str(), c->getHealth(), c->maxHealth,
             c->getBuffShield(), c->getBuffDmg(), c->IsHidden() ? "YES" : "NO",
             c->canUseSpecialPower(roundCount) ? "READY" : "WAIT");
    }
  }
  printw("--------------------------------------------------------------------\n\n");

  printw("                         VS  ( COMBAT ZONE )                        \n\n");

  printw("[ PLAYER 1 TEAM ]    Energy: %d\n", p1Energy);
  printw("--------------------------------------------------------------------\n");
  for (size_t i = 0; i < p1.getCards().size(); ++i) {
    const card *c = p1.getCards()[i];
    if (c == nullptr) {
      printw(" [%zu] <empty slot>\n", i + 1);
      continue;
    }
    if (c->isDead()) {
      printw(" [%zu] %-16s | DEFEATED\n", i + 1, c->getName().c_str());
    } else {
      printw(" [%zu] %-16s | HP:%4d/%-4d | Shield:%4d | Buff:x%.1f | Hidden:%s | Special:%s\n",
             i + 1, c->getName().c_str(), c->getHealth(), c->maxHealth,
             c->getBuffShield(), c->getBuffDmg(), c->IsHidden() ? "YES" : "NO",
             c->canUseSpecialPower(roundCount) ? "READY" : "WAIT");
    }
  }
  printw("--------------------------------------------------------------------\n\n");

  printw("=========================== ACTION LOG =============================\n");
  printw(" > %s\n", actionLog.c_str());
  printw("====================================================================\n");

  refresh();
}

inline int getChoice(const std::string &promptMessage, int maxOptions) {
  printw("\n%s (Press 1-%d or 'q' to Quit): ", promptMessage.c_str(), maxOptions);
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
