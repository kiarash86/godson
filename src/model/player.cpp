#include "../../include/model/player.h"

void player::setCards(std::vector<int> crds) {

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
    case 5:
    //  cards.push_back(new pouyaKazhdom);

      break;
    case 6:
    //  cards.push_back(new sirShariar);

      break;
    }
  }
}
