#include "pool.h"
#include <iostream>
#include <algorithm>
//A pool object will include penjing and a vector of fishes

Pool::Pool(int h, int w)
{
    h_ = h;
    w_ = w;
}

int Pool::getH()
{
    return h_;
}

int Pool::getW()
{
    return w_;
}

vector<Fish*> Pool::getFishes()
{
    return fishes;
}

// Add penjing to the pool
// legalPos is a list of possible positions for fishes to move, it will be in side the pool but outside the penjing 
void Pool::setP(Penjing p)
{
    bool check=true;
    for(auto pole:p.getPoles())
        if (pole.x>w_ ||pole.y>h_)
            {
                std::cout <<"Can not put this penjing to the pool as it is too big" << endl;
                check=false;
            }
    if (check)
        p_=p;
    for (int i =0 ;i<=h_; i++)
        for (int j =0 ;j<=w_; j++)
        {
            Position pos(i,j);
            if (!p.checkPointInside(pos))
                legalPos.push_back(pos);
        }    
}

void Pool::show()
{

    cout << "Fishes : "<<fishes.size()<<endl;

    for (auto i : fishes)
    {
        cout << i->name() << " with Pos :" <<i->getPos().x << ","<< i->getPos().y << " and  strength: " << i->getStrength()<< endl;
    }
    cout <<"---------------------------------------------------------------"<<endl;
}

//Add fish to the list of fishes
void Pool::addFish(Fish *f)
{
    if(f)
        fishes.push_back(f);
}

//Check if fishes meet each other, the stronger one eat weaker one
void Pool::fight ()
{
    if(fishes.size() <=1)
        return;

    auto f = [](Fish* a, Fish* b){return a->getStrength() >=b->getStrength();};

    std::sort(fishes.begin(),fishes.end(),f);
    auto it =fishes.begin();
    
    while(it !=fishes.end())
    {
        auto comparePosition = [&]( Fish* a){return (*it)->getPos()==a->getPos();};
        for (auto it2 =it+1;it2!=fishes.end();it2++)
            if(comparePosition(*it2))
                (*it)->eat(*it2);
        //Remove killed fishes eaten by *it
        auto killed = std::remove_if(it+1,fishes.end(),comparePosition); 
        fishes.erase(killed,fishes.end());
        it++;
    }
}

//Every fish in pool makes move, check if is there any died fish (strength <0) then remove it
void Pool::makeMove()
{
    for (auto it =fishes.begin();it!=fishes.end();it++)
    {
        (*it)->move(legalPos);
    }
    auto dead = std::remove_if(fishes.begin(),fishes.end(),[](Fish* f) {return f->getStrength()<=0; }); 
    fishes.erase(dead,fishes.end());
}


