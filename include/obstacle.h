#include <vector>
#include "position.h"
#include <string>

using namespace std;
class Obstacle
{
    std::vector<Position> poles;
    std::string name_;
    public :
        Obstacle ()= default;
        Obstacle( vector<Position> p,std::string );

        std::vector<Position> getPoles();
        bool checkPointInside(Position);
        std::string name();
};
