#include "pool.h"
#include <iostream>
#include <algorithm>
//A pool object will include Obstacle and a vector of fishes

Pool::Pool(int h, int w)
{
    h_ = h;
    w_ = w;
    for (int i =0 ;i<=h_; i++)
        for (int j =0 ;j<=w_; j++)
        {
            Position pos(i,j);
            legalPos.push_back(pos);
        }
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
//LegalPos is vector of posible position for fishes to move to
vector<Position> Pool::getLegalPos()
{
    return legalPos;
}

//blindPos is vector of position that cover by sea weed, fishes will not fight there
vector<Position> Pool::getBlindPos()
{
    return blindPos;
}
// Add Obstacle to the pool if it is not bigger than the pool
// legalPos is a list of possible positions for fishes to move, it will be in side the pool but outside the Obstacle 
void Pool::setObstacle(Obstacle p)
{
    bool check=true;
    for(auto pole:p.getPoles())
        if (pole.x>w_ ||pole.y>h_)
            {
                std::cout <<"Can not put this " <<p.name()<< " to the pool as it is too big" << endl;
                check=false;
            }
    if (check)
        p_=p;
    
    auto checkInside =[&](Position pos){return p.checkPointInside(pos);};
    for(auto pos:legalPos)
    {
        if(p.name()=="Penjing")
        {
            auto illegal = std::remove_if(legalPos.begin(),legalPos.end(),checkInside);
            legalPos.erase(illegal,legalPos.end());
        }
        else if (p.name()=="SeaWeed")
            if (p.checkPointInside(pos))
                blindPos.push_back(pos);
    }

}

/*void Pool::show()
{
    cout <<"---------------------------------------------------------------"<<endl;

    cout << "Fishes : "<<fishes.size()<<endl;
    vector<Position> Shark,CatFish,SwordFish;
    for (auto i : fishes)
    {
        cout << i->name() << " with Pos :" <<i->getPos().x << ","<< i->getPos().y << " and  strength: " << i->getStrength()<< endl;
        if(i->name() == "Shark")
            Shark.push_back(i->getPos());
        else if(i->name() == "Sword Fish")
            SwordFish.push_back(i->getPos());
        else
            CatFish.push_back(i->getPos());
    }

    for (int i=h_;i>=0;i--)
        {
            cout<< i<<"\t|";
            for (int j=0;j<=w_;j++)
                {
                    Position tmp(j,i);
                    if (std::find(Shark.begin(),Shark.end(),tmp)!=Shark.end())
                        cout << "S|";
                    else if (std::find(SwordFish.begin(),SwordFish.end(),tmp)!=SwordFish.end())
                        cout << "W|";
                    else if (std::find(CatFish.begin(),CatFish.end(),tmp)!=CatFish.end())
                        cout << "C|";
                    else if (std::find(blindPos.begin(),blindPos.end(),tmp)!=blindPos.end())
                        cout<<"B|";
                    else if(std::find(legalPos.begin(),legalPos.end(),tmp)!=legalPos.end())
                        cout << "_|";
                    else
                        cout<<"X|";
                }
            cout<<endl;
        }
    cout <<" \t|";
    for (int i=0;i<=w_;i++)
        cout << i<< "|";
    cout << endl;
    cout <<"---------------------------------------------------------------"<<endl;
        
}*/


void Pool::show()
{
    cout <<"---------------------------------------------------------------"<<endl;

    cout << "Fishes : "<<fishes.size()<<endl;
    vector<Position> Shark,CatFish,SwordFish;
    for (auto i : fishes)
    {
        cout << i->name() << " with Pos :" <<i->getPos().x << ","<< i->getPos().y << " and  strength: " << i->getStrength()<< endl;
        if(i->name() == "Shark")
            Shark.push_back(i->getPos());
        else if(i->name() == "Sword Fish")
            SwordFish.push_back(i->getPos());
        else
            CatFish.push_back(i->getPos());
    }

    for (int i=h_;i>=0;i--)
        {
            cout<< i<<"\t|";
            for (int j=0;j<=w_;j++)
                {
                    Position tmp(j,i);
                    if (std::find(Shark.begin(),Shark.end(),tmp)!=Shark.end())
                        cout<<"\033[1;34mS\033[0m"<<"|";
                    else if (std::find(SwordFish.begin(),SwordFish.end(),tmp)!=SwordFish.end())
                        cout<<"\033[1;34mW\033[0m"<<"|";
                    else if (std::find(CatFish.begin(),CatFish.end(),tmp)!=CatFish.end())
                        cout<<"\033[1;34mC\033[0m"<<"|";
                    else if (std::find(blindPos.begin(),blindPos.end(),tmp)!=blindPos.end())
                        cout<<"\033[1;32mB\033[0m"<<"|";
                    else if(std::find(legalPos.begin(),legalPos.end(),tmp)!=legalPos.end())
                        cout << "_|";
                    else
                        cout<<"\033[1;31mX\033[0m"<<"|";
                }
            cout<<endl;
        }
    cout <<" \t|";
    for (int i=0;i<=w_;i++)
        cout << i<< "|";
    cout << endl;
    cout <<"---------------------------------------------------------------"<<endl;
        
}

//Add fish to the list of fishes
void Pool::addFish(Fish *f)
{
    if(f)
        fishes.push_back(f);
}

/*Check if fishes meet each other,
if they meet in the sea weed, nothing happens
else the stronger one eat weaker one*/
void Pool::fight ()
{
    if(fishes.size() <=1)
        return;

    auto f = [&](Fish* a, Fish* b){return a->getStrength() >b->getStrength();};

    std::sort(fishes.begin(),fishes.end(),f);
    auto it =fishes.begin();
    
    while(it !=fishes.end())
    {
        if (std::find(blindPos.begin(),blindPos.end(),(*it)->getPos())==blindPos.end())
        {
            auto comparePosition = [&]( Fish* a){return (*it)->getPos()==a->getPos();};
            for (auto it2 =it+1;it2!=fishes.end();it2++)
                if(comparePosition(*it2))
                    {
                        (*it)->eat(*it2);
                        cout << (*it)->name() << " ate " << (*it2)->name() << endl;
                    }
            //Remove killed fishes eaten by *it
            auto killed = std::remove_if(it+1,fishes.end(),comparePosition); 
            fishes.erase(killed,fishes.end());
        }
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


