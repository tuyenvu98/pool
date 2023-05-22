#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "position.h"

//Define strength and decreasing rate for each type of fish
#define CATFISH 500
#define CATFISHRATE 2
#define SWORDFISH 300
#define SWORDFISHRATE 1
#define SHARK 1000
#define SHARKRATE 5
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
