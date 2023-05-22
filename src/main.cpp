#include "fishfactory.h"
#include "pool.h"
#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std ;
/* Setup
 - Create a pool with size w*h
 - Create a penjing with a vector of poles coordinate and add it to the Pool
 - Create fishes and put them to fishes list of the Pool
 - In each loop, every fish make move and the stronger one eat weak one if they meet each other
 - The game will be over when only a fish left*/

int main()
{
    Pool pool(20,20);
    vector<Position> p = {{0,0},{2,3}, {4,0}};
    Penjing pen(p);
    FishFactory fac;
    Fish* f1 = fac.create("SwordFish");
    Fish* f2 = fac.create("CatFish");
    Fish* f3 = fac.create("Shark");
    pool.addFish (f1);
    pool.addFish (f2);
    pool.addFish (f3);
    pool.setP(pen);
    int step = 0;
    while(pool.getFishes().size() >1)
    {
        step ++;
        pool.show();
        pool.makeMove();
        pool.fight();
        usleep (500000);
    }
    cout << "Game over after " << step<< " steps" << endl;
    pool.show();
    delete f1;
    delete f2;
    delete f3;
      
    return 0;
}

