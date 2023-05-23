    
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Point.hpp"
#include <cmath>
using namespace std;

namespace ariel{
 
   
Point::Point(){
    this->X = 0;
    this->Y = 0;
}

Point::Point(double poin_x, double poin_y) : X(poin_x), Y(poin_y){

}


double Point:: Get_X(){
    return this->X;
}

double Point::Get_Y(){
    return this->Y;
}

void Point::Set_x(double poin_x){
    this->X=poin_x;
}

void Point::Set_Y(double poin_y){
    this->Y =poin_y;
}

double Point::distance(Point poin){
    double newX = poin.Get_X();
    double newY = poin.Get_Y();
    double thisX = this->X;
    double thisY = this->Y;
    double dis = sqrt(((newY - thisY) *(newY - thisY))  + ((newX - thisX) * (newX - thisX)));
    return dis;
}

string Point::print(){
    string s = "(" + to_string(this->Get_X()) + "," + to_string(this->Get_Y())+")";
    return s; 
}

Point Point::moveTowards(Point start, Point end, double dist){
    if(dist<0){
        throw invalid_argument("the dis mast be bigger then 0");
    }

    double dis = start.distance(end);
    if(dis <= dist){
        return end;
    }
    double ratio = dist / dis;
    double new_x = start.Get_X()+ ratio*(end.Get_X() - start.Get_X());
    double new_y = start.Get_Y()+ ratio*(end.Get_Y() - start.Get_Y());
    Point res(new_x, new_y);
    return res;
}

}