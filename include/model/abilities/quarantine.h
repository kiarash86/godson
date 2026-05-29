#include <vector>
#include "ability.h"
class quarantine : public ability
{
private:
    card *owner;
    card *findTeammateWithLowestHealth(const std::vector<card *> &team);
    void healChosenTeammate(card *);

public:
    void excute(std::vector<card *> &Team, std::vector<card *> &enemy, int tagetIndex) override;

    quarantine(card *);
    ~quarantine();
};
