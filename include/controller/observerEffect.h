#include "../model/cards/card.h"
class observerEffect {
public:
  bool isFinished() const { return !howManyRound; }

  virtual void turnEnded(bool &reverseWorld) { howManyRound--; }

  virtual void finishedAllRoundNeeded(bool &reverseWorld) = 0;

protected:
  int howManyRound{};
  card *onWho;

  virtual ~observerEffect() = 0;
  observerEffect(card *&onWho, int howManyRound): onWho(onWho), howManyRound(howManyRound){};
};
