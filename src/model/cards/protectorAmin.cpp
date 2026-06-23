#include "../../../include/model/cards/protectorAmin.h"
#include "../../../include/model/abilities/aminProtector/lastBullet.h"
#include "../../../include/model/abilities/aminProtector/selfHit.h"
#include "../../../include/model/abilities/aminProtector/cryOfInsecurity.h"

protectorAmin::protectorAmin() : card("protectorAmin", 500, 3, "Healer")
{
    addAbility(new lastBullet(this));
    addAbility(new selfHit(this));
    addAbility(new cryOfInsecurity(this));
}
