#pragma once
class Position
{
    public :
        int x;
        int y;
        Position()
        {
            this->x=0;
            this->y=0;
        }
        bool operator==(Position rhs)
        {
            return ((this->x== rhs.x) && (this->y==rhs.y));
        }
        Position (int x,int y)
        {
            this->x=x;
            this->y=y;
        }
};