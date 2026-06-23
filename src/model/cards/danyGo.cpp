#include "../../../include/model/cards/danyGo.h"
#include "../../../include/model/abilities/danyGo/hooked.h"
#include "../../../include/model/abilities/danyGo/elephantKiller.h"
#include "../../../include/model/abilities/danyGo/familyTrench.h"

danyGo::danyGo() : card("danyGo", 600, 4, "Defender")
{
    addAbility(new hooked(this));
    addAbility(new elephantKiller(this));
    addAbility(new familyTrench(this));
}
