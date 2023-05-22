#include "fish.h"


class SwordFish: public Fish
{
    public :
        SwordFish ();
        SwordFish (int ,int );
        std::string name();
        void move(std::vector<Position> );

};
