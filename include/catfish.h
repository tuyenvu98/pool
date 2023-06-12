#include "fish.h"
#define CATFISH 500
#define CATFISHRATE 2
#define CATFISHSTEP 3

class CatFish: public Fish
{
    public :
        CatFish ();
        CatFish (int ,int );
        std::string name();
        void move(std::vector<Position> p);
};
