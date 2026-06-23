#include "../../../include/model/cards/drWhite.h"
#include "../../../include/model/abilities/drWhite/aspirin.h"
#include "../../../include/model/abilities/drWhite/doping.h"
#include "../../../include/model/abilities/drWhite/operationRoom.h"

drWhite::drWhite() : card("drWhite", 550, 4, "Healer")
{
    addAbility(new aspirin(this));
    addAbility(new doping(this));
    addAbility(new operationRoom(this));
}
