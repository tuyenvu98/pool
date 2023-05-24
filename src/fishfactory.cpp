#include "fishfactory.h"

FishFactory::FishFactory(std::vector<Position> legalPos)
{
    legalPos_= legalPos;
}
 
Fish* FishFactory::create (std::string type)
{
    int n=random(legalPos_.size()-1);
    Position pos = legalPos_[n];
    if (type == "CatFish")
    {
      return new CatFish(pos.x,pos.y);
    }
    else if (type == "SwordFish")
    {
      return new SwordFish(pos.x,pos.y);
    }
    else if (type == "Shark")
    {
      return new Shark(pos.x,pos.y);
    }
    else 
    {
      std::cout<< "There is no fish type " << type << std::endl;
      return nullptr;
    }
}
 

 