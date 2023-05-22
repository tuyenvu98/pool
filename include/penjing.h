#include <vector>
#include "position.h"
using namespace std;
class Penjing
{
    std::vector<Position> poles;
    public :
        Penjing ()= default;
        Penjing( vector<Position> p);

        std::vector<Position> getPoles();
        bool checkPointInside(Position);
};
