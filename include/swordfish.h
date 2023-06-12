#include "fish.h"
#define SWORDFISH 300
#define SWORDFISHRATE 1
#define SWORDFISHSTEP 2

class SwordFish: public Fish
{
    public :
        SwordFish ();
        SwordFish (int ,int );
        std::string name();
        void move(std::vector<Position> );

};
