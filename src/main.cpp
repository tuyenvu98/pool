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
Pool setUp()
{
    int h=0;
    int w=0;
    cout << "Enter height and wide of the pool :" << endl;
    while (h<=0 ||w <=0)
        cin >> h>>w;
    Pool pool(h,w);
    vector<Position> p = {{2,0},{4,4},{7,0}};
    Obstacle pen(p,"Penjing");
    vector<Position> sw = {{0,5},{6,8},{8,3}};

    Obstacle seaWeed(sw,"SeaWeed");
    pool.setObstacle(pen);
    pool.setObstacle(seaWeed);
    FishFactory fac(pool.getLegalPos());
    unsigned int shark, sword,cat;
    cout << "Enter the number of Shark, Sword fish and Cat fish to put to the pool :" << endl;
    cin >> shark >>sword>> cat;
    for(int i=0;i<shark;i++)
        pool.addFish(fac.create("Shark"));
    for(int i=0;i<sword;i++)
        pool.addFish(fac.create("SwordFish"));
    for(int i=0;i<cat;i++)
        pool.addFish(fac.create("CatFish"));
    return pool;

}

Pool def()
{
    Pool pool(10,10);
    vector<Position> p = {{2,0},{4,4},{7,0}};
    Obstacle pen(p,"Penjing");
    pool.setObstacle(pen);
    vector<Position> sw = {{3,5},{6,8},{6,5}};
    Obstacle seaWeed(sw,"SeaWeed");
    pool.setObstacle(seaWeed);
    FishFactory fac(pool.getLegalPos());
    Fish* f1 = fac.create("SwordFish");
    Fish* f2 = fac.create("CatFish");
    Fish* f3 = fac.create("Shark");
    pool.addFish (f1);
    pool.addFish (f2);
    pool.addFish (f3);
    return pool;
}

int main()
{
    Pool pool;
    cout << "Using default setup ? :" << endl;
    cout << "0.Yes  1.No" << endl;
    int mode;
    cin >> mode;
    if(mode) 
        pool = setUp();
    else
        pool =def();
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
    for(auto fish :pool.getFishes())
        delete fish;
      
    return 0;
}

