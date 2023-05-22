#include "swordfish.h"
#include <stdlib.h> 
#include <vector>
#include <algorithm>


SwordFish::SwordFish ()
{
    strength = SWORDFISH;
}

SwordFish::SwordFish (int x,int y )
{
    pos.x= x;
    pos.y= y;
    strength = SWORDFISH;
}

std::string SwordFish::name()
{
    return "Sword Fish";
}
/*Each fish has beginning strength SWORDFISH, and its strength decreases by SWORDFISHRATE % after each move
Sword fish move randomly to any possible position*/

void SwordFish::move(std::vector<Position> p)
{
    Position r(-1,-1);
    while(std::find(p.begin(),p.end(),r)==p.end())
    {
        r.x=rand()%50;
        r.y=rand()%50;
    }
    pos=r;
    strength -= SWORDFISH*SWORDFISHRATE*0.01;

}

