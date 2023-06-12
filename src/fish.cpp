#include "fish.h"

Fish::Fish (int x,int y )
{
    pos.x= x;
    pos.y= y;
}

//Return current possition of the fish
Position Fish::getPos()
{
    return pos;
}

//Return strength of the fish
int Fish::getStrength()
{
    return strength;
}

//Eat the weaker fish
void Fish::eat(Fish *f)
{
    strength += f->strength;

}
