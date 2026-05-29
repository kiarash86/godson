#include"observerEffect.h"
class BombEffect :  public observerEffect
{
private:
    int dmgBuff{1};
public:
//we use the buff of the time that bombed on target
    BombEffect(card *onWho , float dmgBuff) :observerEffect(onWho , 2) , dmgBuff(dmgBuff){};
    ~BombEffect();
    void finishedAllRoundNeeded() override
    {
       if (onWho->getHealth() <= dmgBuff* 360)
       {
           onWho->dmgWithBomb( 360* dmgBuff);
            return;
       }
       
       onWho->damage(200 *dmgBuff);
        

    }
};

