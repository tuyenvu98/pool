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
Shark move randomly up down left or right with step in range [0,2]*/
void Shark::move(std::vector<Position> p)
{
    Position r(-1,-1);
    while(std::find(p.begin(),p.end(),r)==p.end())
    {
        auto f = []{return (rand() % 3) * (rand() & 1 ? 1 : -1);};
        int dx = f();
        int dy = f();
        r.x =pos.x +dx;
        r.y =pos.y +dy; 
    } 
    pos= r;
    strength -= SHARK*SHARKRATE*0.01 ;

}


