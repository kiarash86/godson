#include <vector>
#include "ability.h"
class selfHit : public ability
{
private:
    card *owner;
    card *chooseRandomTeammate(const std::vector<card *> &team);
    void attackChosenTeammate(card *);
    void healmyself();    
    void healChosenTeammate(card *);
    void attackmyself();

    public : 
    bool excute(gameData gameData) override;

    selfHit(card *);
    ~selfHit();
};
