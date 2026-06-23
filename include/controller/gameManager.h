#pragma once
#include "../view/battleMap.h"
#include "../view/helpMeOptions.h"
#include "../view/helpMeView.h"
#include "../view/preparationGameView.h"
#include "../view/startView.h"
#include "../view/storitesMenu.h"
#include "../view/storyShow.h"

#include "../model/abilities/aminProtector/cryOfInsecurity.h"
#include "../model/abilities/aminProtector/lastBullet.h"
#include "../model/abilities/aminProtector/selfHit.h"
#include "../model/abilities/bigTaha/brotherRevenge.h"
#include "../model/abilities/bigTaha/volley.h"
#include "../model/abilities/bigTaha/xRay.h"
#include "../model/abilities/danyGo/elephantKiller.h"
#include "../model/abilities/danyGo/familyTrench.h"
#include "../model/abilities/danyGo/hooked.h"
#include "../model/abilities/drWhite/aspirin.h"
#include "../model/abilities/drWhite/doping.h"
#include "../model/abilities/drWhite/operationRoom.h"
#include "../model/abilities/littleTaha/bloodSerum.h"
#include "../model/abilities/littleTaha/quarantine.h"
#include "../model/abilities/littleTaha/sharpBlade.h"

#include "../model/player.h"
#include "observerEffect.h"

#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

class gameManager {
private:
  player player1;
  player player2;
  std::vector<observerEffect *> effects;
  int round{1};
  bool reverseWorld{false};

  struct abilityStruct {
    bool needsTarget{false};
    bool targetIsAlly{false};
    bool allowDeadTarget{false};
    int energyCost{0};
  };

  static std::vector<std::string> abilityLabelsForHero(const card *hero) {
    std::vector<std::string> labels;
    if (hero == nullptr) {
      return {"Ability 1", "Ability 2", "Special"};
    }

    for (const ability *ab : hero->getAbilities()) {
      if (ab != nullptr) {
        labels.push_back(ab->getLabel());
      }
    }

    if (labels.empty()) {
      return {"Ability 1", "Ability 2", "Special"};
    }
    return labels;
  }

  void progressCards(player &p) {
    for (card *c : p.getCards()) {
      if (c != nullptr) {
        c->addRound();
      }
    }
  }

  static int firstTeamEnergyForRound(int roundNumber) {
    if (roundNumber <= 1) {
      return 5;
    }
    if (roundNumber == 2) {
      return 8;
    }
    if (roundNumber == 3) {
      return 9;
    }
    return 10;
  }

  static int secondTeamEnergyForRound(int roundNumber) {
    if (roundNumber <= 1) {
      return 8;
    }
    if (roundNumber == 2) {
      return 9;
    }
    return 10;
  }

  static int aliveHeroes(const player &p) {
    int count = 0;
    for (const card *c : p.getCards()) {
      if (c != nullptr && !c->isDead()) {
        ++count;
      }
    }
    return count;
  }

  static bool hasAliveHeroes(const player &p) { return aliveHeroes(p) > 0; }

  static bool hasPlayableAbility(const player &p, int energy, int roundNumber) {
    for (const card *c : p.getCards()) {
      if (c == nullptr || c->isDead()) {
        continue;
      }
      for (const ability *ab : c->getAbilities()) {
        if (ab != nullptr && ab->canBeExcuted(roundNumber) && ab->getEneryCost() <= energy) {
          return true;
        }
      }
    }
    return false;
  }

  static bool hasValidTargetsForAbility(const player &p, const abilityStruct &structAbility) {
    for (const card *c : p.getCards()) {
      if (c == nullptr) {
        continue;
      }
      if (!structAbility.allowDeadTarget && c->isDead()) {
        continue;
      }
      return true;
    }
    return false;
  }

  static std::vector<int> livingindexs(const std::vector<card *> &team, bool allowDead = false) {
    std::vector<int> indexs;
    for (size_t i = 0; i < team.size(); ++i) {
      if (team[i] == nullptr) {
        continue;
      }
      if (!allowDead && team[i]->isDead()) {
        continue;
      }
      indexs.push_back((i));
    }
    return indexs;
  }


  abilityStruct getabilityStruct(const card *hero, int abilityIndex) const {
    abilityStruct structAbility{};

    if (hero == nullptr) {
      return structAbility;
    }

    const ability *ab = hero->getAbility(static_cast<size_t>(abilityIndex));
    if (ab == nullptr) {
      return structAbility;
    }

    structAbility.needsTarget = ab->requiresTarget();
    structAbility.targetIsAlly = ab->targetIsTeamMate();
    structAbility.allowDeadTarget = ab->canTargetDead();
    structAbility.energyCost = ab->getEneryCost();
    return structAbility;
  }

  void deleteAllEffects() {
    for (observerEffect *effect : effects) {
      delete effect;
    }
    effects.clear();
  }

  void processEffects() {
    for (size_t i = 0; i < effects.size();) {
      observerEffect *effect = effects[i];
      effect->turnEnded(reverseWorld);

      if (effect->isFinished()) {
        effect->finishedAllRoundNeeded(reverseWorld);
        delete effect;
        effects.erase(effects.begin() + (i));
      } else {
        ++i;
      }
    }
  }

  int chooseHeroIndex(const player &p, const std::string &title, bool allowDead = false) {
    auto indexs = livingindexs(p.getCards(), allowDead);
    if (indexs.empty()) {
      return -1;
    }

    printw("\n\n==================================================\n");
    printw("%s\n", title.c_str());
    printw("==================================================\n\n");
    for (size_t i = 0; i < indexs.size(); ++i) {
      card *c = p.getCards()[(indexs[i])];
      if (c->isDead()) {
        printw(" [%zu] %s : DEFEATED\n", i + 1, c->getName().c_str());
      } else {
        printw(" [%zu] %s | HP: %d | Buff: %.1f\n", i + 1, c->getName().c_str(),
               c->getHealth(), c->getBuffDmg());
      }
    }
    refresh();

    int selected = getChoice(title, (indexs.size()));
    if (selected < 0) {
      return -1;
    }
    return indexs[(selected)];
  }

  int chooseTargetIndex(const std::vector<card *> &team,
                        const std::string &title, bool allowDead = false) {
    auto indexs = livingindexs(team, allowDead);
    if (indexs.empty()) {
      return -1;
    }

    printw("\n\n==================================================\n\n");
    printw("%s\n", title.c_str());
    printw("==================================================\n\n");
    for (size_t i = 0; i < indexs.size(); ++i) {
      card *c = team[(indexs[i])];
      if (c->isDead()) {
        printw(" [%zu] %s : DEFEATED\n", i + 1, c->getName().c_str());
      } else {
        printw(" [%zu] %s | HP: %d | Buff: %.1f\n", i + 1, c->getName().c_str(),
               c->getHealth(), c->getBuffDmg());
      }
    }
    refresh();

    int selected = getChoice(title, (indexs.size()));
    if (selected < 0) {
      return -1;
    }
    return indexs[(selected)];
  }

  int chooseAbilityIndex(const card *hero, int roundNumber) {
    if (hero == nullptr) {
      return -1;
    }

    printw("\n\n==================================================\n");
    printw("Choose ability for %s\n", hero->getName().c_str());
    printw("==================================================\n\n");

    const auto &abilities = hero->getAbilities();
    std::vector<int> availableIndices;
    for (size_t i = 0; i < abilities.size(); ++i) {
      const ability *ab = abilities[i];
      if (ab == nullptr) {
        continue;
      }

      const bool ready = ab->canBeExcuted(roundNumber);
      printw(" [%zu] %-30s | Energy: %d | Target: %s | %s\n", i + 1,
             ab->getLabel().c_str(), ab->getEneryCost(),
             ab->requiresTarget() ? "YES" : "NO",
             ready ? "READY" : "LOCKED");

      if (ready) {
        availableIndices.push_back(static_cast<int>(i));
      }
    }

    const ability *specialAbility = hero->getAbility(2);
    if (specialAbility != nullptr && specialAbility->isSpecialPower()) {
      printw("\nSpecial status: %s", specialAbility->canBeExcuted(roundNumber) ? "READY" : "LOCKED");
      if (!specialAbility->canBeExcuted(roundNumber)) {
        printw(" (%d rounds left)", specialAbility->getRoundsLeft(roundNumber));
      }
    }
    printw("\n");
    refresh();

    if (availableIndices.empty()) {
      return -1;
    }

    int selected = getChoice("Choose an ability", static_cast<int>(availableIndices.size()));
    if (selected < 0) {
      return -1;
    }
    return availableIndices[static_cast<size_t>(selected)];
  }

  bool executeAbility(card *hero, int abilityIndex, gameData &data) {


    if (hero == nullptr) {
      return false;
    }

    ability *ab = hero->getAbility(static_cast<size_t>(abilityIndex));
    if (ab == nullptr || !ab->canBeExcuted(data.round)) {
      return false;
    }

    const bool ok = ab->excute(data);
    if (ok) {
      ab->setLastRoundNumberUsed(data.round);
      if (ab->isSpecialPower()) {
        hero->markSpecialPowerUsed(data.round);
      }
    }
    return ok;
  }

  bool TurnProcess(player &actingPlayer, player &enemyPlayer, player &displayPlayer1, player &displayPlayer2, int turnLabel,
                     int &energy, int enemyEnergy, std::string &actionLog, bool &quitBattle) {
    while (hasAliveHeroes(actingPlayer) && hasAliveHeroes(enemyPlayer)) {
      if (energy <= 0 || !hasPlayableAbility(actingPlayer, energy, round)) {
        actionLog = "No playable ability left. Turn ended.";
        draw(displayPlayer1, displayPlayer2, round, turnLabel, energy, enemyEnergy, actionLog);
        refresh();
        getch();
        break;
      }

      draw(displayPlayer1, displayPlayer2, round, turnLabel, energy, enemyEnergy, actionLog);
      printw("\nEnergy: %d\n", energy);
      refresh();

      int heroIndex = chooseHeroIndex(actingPlayer, "Choose a hero to act");
      if (heroIndex < 0) {
        quitBattle = true;
        return false;
      }

      card *hero = actingPlayer.getCards()[heroIndex];
      if (hero == nullptr || hero->isDead()) {
        actionLog = "Invalid hero choice.";
        continue;
      }

      int abilityIndex = chooseAbilityIndex(hero, round);
      if (abilityIndex < 0) {
        quitBattle = true;
        return false;
      }

      abilityStruct structAbility = getabilityStruct(hero, abilityIndex);
      ability *selectedAbility = hero->getAbility(static_cast<size_t>(abilityIndex));
      if (selectedAbility == nullptr) {
        actionLog = "Ability missing.";
        continue;
      }

      if (energy < structAbility.energyCost) {
        if (!hasPlayableAbility(actingPlayer, energy, round)) {
          actionLog = "Not enough energy. Turn ended.";
          draw(displayPlayer1, displayPlayer2, round, turnLabel, energy, enemyEnergy, actionLog);
          refresh();
          getch();
          break;
        }
        actionLog = "Not enough energy for this ability.";
        continue;
      }

      gameData data{actingPlayer.getCards(),
                    enemyPlayer.getCards(),
                    -1,
                    effects,
                    round,
                    reverseWorld};

      if (structAbility.needsTarget) {
        const player &targetPlayer = structAbility.targetIsAlly ? actingPlayer : enemyPlayer;
        if (!hasValidTargetsForAbility(targetPlayer, structAbility)) {
          actionLog = "No valid target exists for this ability.";
          if (!hasPlayableAbility(actingPlayer, energy, round)) {
            draw(displayPlayer1, displayPlayer2, round, turnLabel, energy, enemyEnergy, actionLog);
            refresh();
            getch();
            break;
          }
          continue;
        }

        if (structAbility.targetIsAlly) {
          data.targetIndex =
              chooseTargetIndex(actingPlayer.getCards(),
                                "Choose an ally target", structAbility.allowDeadTarget);
        } else {
          data.targetIndex = chooseTargetIndex(enemyPlayer.getCards(),
                                               "Choose an enemy target", structAbility.allowDeadTarget);
        }

        if (data.targetIndex < 0) {
          actionLog = "No valid target.";
          continue;
        }
      }

      if (!executeAbility(hero, abilityIndex, data)) {
        actionLog = "Ability could not be used.";
        continue;
      }

      energy -= structAbility.energyCost;
      if (energy < 0) {
        energy = 0;
      }

      actionLog = hero->getName() + " used " + selectedAbility->getLabel() + ".";

      draw(displayPlayer1, displayPlayer2, round, turnLabel, energy, enemyEnergy, actionLog);
      printw("\nAction applied.");
      if (energy == 0 || !hasPlayableAbility(actingPlayer, energy, round)) {
        printw("\nTurn ended.");
      }
      refresh();
      getch();

      if (!hasAliveHeroes(enemyPlayer)) {
        return true;
      }
    }

    return true;
  }

public:
  ~gameManager() { deleteAllEffects(); }

  void whereToGoFromStoriesMenu() {
    while (true) {
      int index = ShowStoriesMenuOption();
      if (index == 5) {
        break;
      }
      handleStoriesMenu(index);
    }
  }

  void whereToGoFromHelpMenu() {
    while (true) {
      int index = ShowHelpMeMenuOption();
      if (index == 2) {
        break;
      }
      handleOptionsMenu(index);
    }
  }

  int whereToGoFromMainMenu() {
    int index = ShowStartMenuOption();
    switch (index) {
    case 0:
      round = 1;
      reverseWorld = false;
      deleteAllEffects();
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
    default:
      break;
    }
    return 0;
  }

  void Battle() {
    bool quitBattle = false;
    int startingSide = std::rand() % 2;
    std::string actionLog =
        startingSide == 0 ? "Player 1 starts." : "Player 2 starts.";

    while (round <= 15 && hasAliveHeroes(player1) && hasAliveHeroes(player2) &&
           !quitBattle) {
      int p1Energy = firstTeamEnergyForRound(round);
      int p2Energy = secondTeamEnergyForRound(round);

      if (startingSide == 0) {
        TurnProcess(player1, player2, player1, player2, 1, p1Energy, p2Energy, actionLog, quitBattle);
        if (quitBattle || !hasAliveHeroes(player2) ||
            !hasAliveHeroes(player1)) {
          break;
        }
        TurnProcess(player2, player1, player1, player2, 2, p2Energy, p1Energy, actionLog, quitBattle);
      } else {
        TurnProcess(player2, player1, player1, player2, 2, p2Energy, p1Energy, actionLog, quitBattle);
        if (quitBattle || !hasAliveHeroes(player2) ||
            !hasAliveHeroes(player1)) {
          break;
        }
        TurnProcess(player1, player2, player1, player2, 1, p1Energy, p2Energy, actionLog, quitBattle);
      }

      progressCards(player1);
      progressCards(player2);
      processEffects();
      if (!hasAliveHeroes(player1) || !hasAliveHeroes(player2)) {
        break;
      }

      ++round;
      startingSide = 1 - startingSide;
    }

    draw(player1, player2, round, startingSide == 0 ? 1 : 2, 0, 0, actionLog);
    printw("\n\n=== MATCH RESULT ===\n");
    if (!hasAliveHeroes(player1) && !hasAliveHeroes(player2)) {
      printw("DRAW: both teams were eliminated.\n");
    } else if (!hasAliveHeroes(player2)) {
      printw("PLAYER 1 WINS!\n");
    } else if (!hasAliveHeroes(player1)) {
      printw("PLAYER 2 WINS!\n");
    } else {
      int alive1 = aliveHeroes(player1);
      int alive2 = aliveHeroes(player2);
      if (alive1 > alive2) {
        printw("PLAYER 1 WINS by remaining heroes.\n");
      } else if (alive2 > alive1) {
        printw("PLAYER 2 WINS by remaining heroes.\n");
      } else {
        printw("DRAW: equal surviving heroes.\n");
      }
    }
    printw("\nPress any key to return to main menu...");
    refresh();
    getch();
  }
};
