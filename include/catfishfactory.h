#include "catfish.h"
#include "fishfactory.h"
#include<string>

//Concrete factory to create cat fish 

class CatFishFactory : public FishFactory
{

public:
  CatFishFactory(std::vector<Position> );
  Fish* create ();
 
};
 