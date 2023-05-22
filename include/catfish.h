#include "fish.h"



class CatFish: public Fish
{
    public :
        CatFish ();
        CatFish (int ,int );
        std::string name();
        void move(std::vector<Position> p);
};
