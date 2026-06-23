#include "../../../include/model/cards/littleTaha.h"
#include "../../../include/model/abilities/littleTaha/sharpBlade.h"
#include "../../../include/model/abilities/littleTaha/bloodSerum.h"
#include "../../../include/model/abilities/littleTaha/quarantine.h"

littleTaha::littleTaha() : card("littleTaha", 500, 3, "Healer")
{
    addAbility(new sharpBlade(this));
    addAbility(new bloodSerum(this));
    addAbility(new quarantine(this));
}
