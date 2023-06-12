#include "sharkfactory.h"

SharkFactory::SharkFactory(std::vector<Position> legalPos)
{
  legalPos_ = legalPos;
}

Fish* SharkFactory::create ()
{
    int n=abs(random(legalPos_.size()-1));
    Position pos = legalPos_[n];
    return new Shark(pos.x,pos.y);
}
 

 