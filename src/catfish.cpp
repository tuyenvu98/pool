#include "catfish.h"
#include <stdlib.h> 
#include <vector>
#include <algorithm>


CatFish::CatFish ()
{
    strength = CATFISH;
}


CatFish::CatFish (int x,int y )
{
    pos.x= x;
    pos.y= y;
    strength = CATFISH;
}

std::string CatFish::name()
{
    return "Cat Fish";
}
        
/*Each fish has beginning strength CATFISH, and its strength decreases by CATFISHRATE % after each move
Cat fish move randomly up down left or right with step in range [0,1]*/
void CatFish::move(std::vector<Position> p)
{
    Position r(-1,-1);
    while(std::find(p.begin(),p.end(),r)==p.end())
    {
        int dx = random(CATFISHSTEP);
        int dy = random(CATFISHSTEP);
        r.x =pos.x +dx;
        r.y =pos.y +dy; 
    } 
    pos= r;
    strength -= CATFISH*CATFISHRATE*0.01 ;
}

