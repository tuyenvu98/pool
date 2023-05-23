#include <vector>
#include "fish.h"
#include "penjing.h"

using namespace std;
class Pool
{
    public:     
        Pool(int,int);
        Pool()=default;
        int getH();
        int getW();
        vector<Fish*> getFishes();
        void setP(Penjing);
        void addFish(Fish *);
        void show();
        void fight();
        void makeMove();


    private :
        int h_;
        int w_;
        Penjing p_ ;
        vector<Fish*> fishes;
        vector<Position> legalPos;

        
};
