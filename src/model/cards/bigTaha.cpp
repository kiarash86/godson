#include "../../../include/model/cards/bigTaha.h"
#include "../../../include/model/abilities/bigTaha/volley.h"
#include "../../../include/model/abilities/bigTaha/xRay.h"
#include "../../../include/model/abilities/bigTaha/brotherRevenge.h"

bigTaha::bigTaha() : card("bigTaha", 500, 4, "Attacker")
{
    addAbility(new volley(this));
    addAbility(new xRay(this));
    addAbility(new brotherRevenge(this));
}
