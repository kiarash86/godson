#include "observerEffect.h"
class healEffect : public observerEffect {
private:
  int healAmount{};

public:
  // we use the buff of the time that bombed on target
  healEffect(card *onWho, int healAmount, int howManyRound)
      : observerEffect(onWho, howManyRound), healAmount(healAmount){};
  void turnEnded(bool &reverseWorld) {
    howManyRound--;
    if (onWho->isDead()) {
      return;
    }
    if (reverseWorld) {
      onWho->damage(healAmount);
    } else {

      onWho->heal(healAmount);
    }
  }
};
