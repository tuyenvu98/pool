#include "swordfish.h"
#include "catfish.h"
#include "shark.h"
#include<string>

//Simple factory to create fish by type name

class FishFactory
{

std::vector<Position> legalPos_;
public:
  FishFactory(std::vector<Position> );
  Fish* create (std::string );
 
};
 