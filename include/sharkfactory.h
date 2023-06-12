#include "shark.h"
#include "fishfactory.h"
#include<string>

//Concrete factory to create shark 

class SharkFactory : public FishFactory
{

public:
  SharkFactory(std::vector<Position> );
  Fish* create ();
 
};
 