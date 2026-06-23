#pragma once

#include "../model/cards/card.h"

class observerEffect {
public:
  observerEffect(card *onWho, int howManyRound) : onWho(onWho), howManyRound(howManyRound) {}
  virtual ~observerEffect() = default;

  bool isFinished() const { return howManyRound <= 0; }
  virtual void turnEnded(bool &reverseWorld) { --howManyRound; }
  virtual void finishedAllRoundNeeded(bool &reverseWorld) = 0;

protected:
  int howManyRound{};
  card *onWho{};
};
