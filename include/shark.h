#include "fish.h"
#define SHARK 1000
#define SHARKRATE 3
#define SHARKSTEP 5


class Shark: public Fish
{
    public :

        Shark ();
        Shark (int ,int  );
        std::string name();
        
        void move(std::vector<Position> );

};
