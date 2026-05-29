#include <vector>
#include "ability.h"
#include "../../controller/BombEffect.h"
class brotherRevenge : public ability
{
private:
    card *owner;
    card *chooseRandomEnemy(const std::vector<card *> &team);
    void bombingChosenEnemy(card *enemy);

public:
    void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex, std::vector<observerEffect *> &effects) override;
    
    brotherRevenge(card *);
    ~brotherRevenge();
};
