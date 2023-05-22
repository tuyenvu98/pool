#include "penjing.h"
#include <cmath>
using namespace std;

Penjing::Penjing( vector<Position> p)
{   
    poles =p;
}

 std::vector<Position> Penjing::getPoles()
{
    return poles;
}

/*To check if a point is inside the penjing (illegal position to move to)
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
    double square = sqrt(per * (per-ab) * (per-bc) * (per -ca));
    return square;
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

bool Penjing::checkPointInside(Position pos)
{

    if(poles.size() <3 || abs( getSquare(pos,poles)-getSquare(*(poles.begin()),poles)) > 1e-9)
        return false;
    return true;
}