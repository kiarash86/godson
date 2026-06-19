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
    void excute(gameData gameData) override;
    
    brotherRevenge(card *);
    ~brotherRevenge();
};
