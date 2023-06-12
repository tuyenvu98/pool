#include "shark.h"
#include <stdlib.h> 
#include <vector>
#include <algorithm>


Shark::Shark ()
{
    strength = SHARK;
}
Shark::Shark (int x,int y )
{
    pos.x= x;
    pos.y= y;
    strength = SHARK;
}

std::string Shark::name()
{
    return "Shark";
}
        
/*Each fish has beginning strength SHARK, and its strength decreases by SHARKRATE % after each move
Shark move randomly in radius SHARKSTEP*/
void Shark::move(std::vector<Position> p)
{
    Position r(-1,-1);
    while(std::find(p.begin(),p.end(),r)==p.end())
    {
        int dx = random(SHARKSTEP);
        int tmp = (int)(sqrt(SHARKSTEP*SHARKSTEP-dx*dx));
        int dy = random(tmp);
        r.x =pos.x +dx;
        r.y =pos.y +dy; 
    } 
    pos= r;
    strength -= SHARK*SHARKRATE*0.01 ;

}


