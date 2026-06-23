#include "../../include/model/player.h"

player::~player()
{
  clearCards();
}

void player::clearCards()
{
  for (card *c : cards)
  {
    delete c;
  }
  cards.clear();
}

void player::setCards(std::vector<int> crds) {

  clearCards();

  for (const auto &crd : crds) {
    switch (crd) {
    case 0:
      cards.push_back(new littleTaha);
      break;
    case 1:
      cards.push_back(new bigTaha);
      break;
    case 2:
      cards.push_back(new drWhite);
      break;
    case 3:
      cards.push_back(new danyGo);
      break;
    case 4:
      cards.push_back(new protectorAmin);
      break;
    default:
      break;
    }
  }
}
