#include <vector>
#include "ability.h"
class aspirin : public ability
{
private:
    card* owner;
    card *chooseRandomTeammate(const std::vector<card *> &team);
    void attackChosenEnemy(card *);
    void healChosenTeammate(card *);


public:
    void excute(gameData gameData) override;

    aspirin(card *);    
    ~aspirin();
};
