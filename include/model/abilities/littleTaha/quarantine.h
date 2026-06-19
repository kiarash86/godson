#include <vector>
#include "ability.h"
class quarantine : public ability
{
private:
    card *owner;
    card *findTeammateWithLowestHealth(const std::vector<card *> &team);
    void healChosenTeammate(card *);

public:
    void excute(gameData gameData) override;

    quarantine(card *);
    ~quarantine();
};
