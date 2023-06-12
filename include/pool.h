#include <vector>
#include "fish.h"
#include "obstacle.h"

using namespace std;
class Pool
{
    public:     
        Pool(int,int);
        Pool()=default;
        int getH();
        int getW();
        vector<Fish*> getFishes();
        void setObstacle(Obstacle);
        void addFish(Fish *);
        void show();
        void fight();
        void makeMove();
        vector<Position> getLegalPos();
        vector<Position> getBlindPos();

    private :
        int h_;
        int w_;
        Obstacle p_ ;
        vector<Fish*> fishes;
        vector<Position> legalPos;
        vector<Position> blindPos;

        
};
