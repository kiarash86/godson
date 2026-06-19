#include <vector>
#include "ability.h"
#include "../../controller/healEffect.h"
class bloodSerum : public ability
{
private:
    card *owner;

public:
    void excute(gameData gameData) override;
    bloodSerum(card *);
};
