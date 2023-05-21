#ifndef POINT_HPP
#define POINT_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

//using namespace ariel;

namespace ariel{

class Point{

    double X;
    double Y;

    public:
        Point();
        Point(double poin_x, double poin_y);

        double Get_X();
        double Get_Y();
        void Set_x(double poin_x);
        void Set_Y(double poin_y);

        double distance(Point poin);
        string print();

        Point static moveTowards(Point start, Point end, double dist);

};
}

#endif