#pragma once
#include <iostream>
#include <string>
#include <cstdlib> 
#include <cmath>
#include <vector>
#include "position.h"

//Define strength, decreasing rate and move step for each type of fish
#define random(n) (rand()%(n+1)) * (rand() & 1 ? 1 : -1)
class Fish
{
    protected :
        int strength;
        Position pos;
    public :
        Fish (){};
        Fish(int,int);
        virtual ~Fish()=default;
        Position getPos();
        int getStrength();
        virtual std::string name()=0;
        void eat(Fish*);
        virtual void move(std::vector<Position> p) =0;
};
