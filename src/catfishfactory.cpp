#include "catfishfactory.h"

CatFishFactory::CatFishFactory(std::vector<Position> legalPos)
{
  legalPos_ = legalPos;
}
 
Fish* CatFishFactory ::create ()
{
    int n=abs(random(legalPos_.size()-1));
    Position pos = legalPos_[n];
    return new CatFish(pos.x,pos.y);
}
 

 