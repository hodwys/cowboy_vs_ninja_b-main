
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Point.hpp"
#include "Character.hpp"
using namespace std;
//using namespace ariel;
namespace ariel{

Character::Character(const string& nam, const Point& loca, int targ) : loc(loca),target(targ),name(nam)  {
}

Character::Character( const string& nam ,const Point& loca) : loc(loca), name(nam){
}

int Character::getTarget(){
    return this->target;
}

string Character::getName(){
    return this->name;
}

void Character::Set_location(Point loca){
    this->loc = loca;
}

void Character::Set_target(int tar){
    this->target = tar;
}

bool Character::isAlive(){
    return target>0;
    
}
double Character:: distance(Character* other){
    return this->getLocation().distance(other->getLocation());
}
void Character::hit(int count_hit){

    if(count_hit < 0){
        throw std::invalid_argument("agfdgdfg");
    }

    this->target = this->target-count_hit;
    if(this->target<=0){
        this->target = 0;
      //  printf("im dead");
        return;    }
   // printf("im ok");
}

Point& Character:: getLocation(){
    return this->loc;
}
 bool Character::get_in_team(){
    return this->is_team;
 }
 void Character::set_in_team(bool sta){
    this->is_team = sta;
 }

}