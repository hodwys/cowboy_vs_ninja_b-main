
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "all_ninja.hpp"
using namespace std;
namespace ariel{


all_ninja:: all_ninja(const string &nam,const Point& loca, int target, int speed): Character(nam,loca, target), speed(speed){
}
void all_ninja:: move(Character * malo){
    if(malo == nullptr){
        throw std::runtime_error("nullptr pointer -move");
    }
    this->Set_location(this->getLocation().moveTowards(this->getLocation(),malo->getLocation(), this->get_speed() ));
}

void all_ninja::slash(Character * malo){
    if(malo == nullptr){
        throw std::runtime_error("nullptr pointer - slash");
    }
    if(this != malo){
        if(this->isAlive() && malo->isAlive()){
            double dis= this->getLocation().distance(malo->getLocation());
            if(dis<1){
                malo->Set_target(malo->getTarget()-40);
            }
            if(malo->getTarget()<0){
                malo->Set_target(0);
            }
        }
        else{
            throw std::runtime_error("somone not alive- slash");
        }
    }
    else{
        throw std::runtime_error("(this == malo - slash");
    }
} 
int all_ninja:: get_speed(){
    return this->speed;
}
string all_ninja::print(){
    string s ="N ";
    if(this->isAlive()){
        s+=" name: "+ this->getName();
        s+= " target: "+to_string(this->getTarget());
    }
    else{
        s+= "  name (" + this->getName() + ") ";
    }
    s+= " location: "+this->getLocation().print();
    return s;

}

}


