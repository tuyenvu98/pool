#include "fish.h"



class Shark: public Fish
{
    public :

        Shark ();
        Shark (int ,int  );
        std::string name();
        
        void move(std::vector<Position> );

};
