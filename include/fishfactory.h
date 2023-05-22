#include "swordfish.h"
#include "catfish.h"
#include "shark.h"
#include<string>

//Simple factory to create fish by type name

class FishFactory
{
public:

 
  Fish* create (std::string type)
  {
    if (type == "CatFish")
    {
      return new CatFish;
    }
    else if (type == "SwordFish")
    {
      return new SwordFish;
    }
    else if (type == "Shark")
    {
      return new Shark;
    }
    else 
    {
      std::cout<< "There is no fish type " << type << std::endl;
      return nullptr;
    }
  }
 
};
 