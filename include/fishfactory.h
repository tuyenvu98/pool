#pragma once
#include<vector>
#include "fish.h"
#include "position.h"

//Base factory to create fish 

class FishFactory
{

protected:
  std::vector<Position> legalPos_;
public:
  virtual Fish* create()=0;
 
};
 