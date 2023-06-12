#include "swordfishfactory.h"

SwordFishFactory::SwordFishFactory(std::vector<Position> legalPos)
{
  legalPos_ = legalPos;
}

Fish* SwordFishFactory ::create ()
{
    int n=abs(random(legalPos_.size()-1));
    Position pos = legalPos_[n];
    return new SwordFish(pos.x,pos.y);
}
 

 