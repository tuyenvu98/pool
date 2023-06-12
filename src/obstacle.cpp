#include "obstacle.h"
#include <cmath>
#include <iostream>


Obstacle::Obstacle( vector<Position> p,string name)
{   
    poles =p;
    name_ =name;
}

std::vector<Position> Obstacle::getPoles()
{
    return poles;
}

std::string Obstacle::name()
{
    return name_;
}


/*To check if a point is inside the Obstacle 
 Ex : point M is inside polygon ABCD when S(MAB)+S(MBC)+S(MCD)+S(MDA) = S(ABCD) */

//Return distance between 2 positions
double length (Position a, Position b)
{
    return sqrt(pow(b.x-a.x,2) + pow(b.y-a.y,2));
}
//Return square of the triangle, knowing 3 poles
double triangleSquare(Position a, Position b, Position c)
{
    double ab = length(a,b);
    double bc = length(b,c);
    double ca = length(a,c);
    
    //Perimeter of triangle
    double per = (ab+bc+ca)/2;
    //Square of triangle
    double square = sqrt(abs(per * (per-ab) * (per-bc) * (per -ca)));
    return (square<1e-6)? 0: square;
}
//Return S(MAB)+S(MBC)+S(MCD)+S(MDA) 
double getSquare(Position p,vector<Position> pos)
{
    if (pos.size() <3)
        return 0;
    double sum=triangleSquare(p,*pos.begin(),*(pos.end()-1));
    vector<Position>::iterator it;
    for (it=pos.begin(); it!=pos.end()-1;it++)
        {
            sum+= triangleSquare(p,*it,*(it+1));
        }
    return sum;
}

bool Obstacle::checkPointInside(Position pos)
{
    //std::cout <<  getSquare(pos,poles)-getSquare(*(poles.begin()),poles)<<std::endl;
    if(poles.size() <3 || abs( getSquare(pos,poles)-getSquare(*(poles.begin()),poles)) > 1e-9)
        return false;
    return true;
}