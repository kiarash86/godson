#include "observerEffect.h"
class reverseWorldEffect : public observerEffect {
private:
  int healAmount{};

public:
  // we use the buff of the time that bombed on target
  reverseWorldEffect(card *onWho, int howManyRound)
      : observerEffect(onWho, howManyRound){};


  void finishedAllRoundNeeded(bool &reverseWorld) override {

    reverseWorld = !reverseWorld;
  }
};
