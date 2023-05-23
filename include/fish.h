#pragma once
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <cmath>
#include <vector>
#include "position.h"

//Define strength, decreasing rate and move step for each type of fish
#define CATFISH 500
#define CATFISHRATE 2
#define CATFISHSTEP 3
#define SWORDFISH 300
#define SWORDFISHRATE 1
#define SWORDFISHSTEP 2
#define SHARK 1000
#define SHARKRATE 3
#define SHARKSTEP 5
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
