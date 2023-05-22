#ifndef CHARACTER
#define CHARACTER


#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Point.hpp"
using namespace std;
namespace ariel{

class Character{

    Point loc;
    int target; 
    string name;
    bool is_team = false;

    public:
        Character(const string& name ,const Point& loc, int target);
        Character(const string& name,const Point& loc);

        int getTarget();
        string getName();

        void Set_location(Point poin);
        void Set_target(int tar);
        bool isAlive();
        double distance(Character* other);
        void hit(int count_hit);
        virtual string print() =0;
        Point& getLocation();
        bool get_in_team();
        void set_in_team(bool sta);
        ///////////////////////////////////////////////
         virtual ~Character() = default ;

            Character(const Character&) = delete; // delete copy constructor
            Character& operator=(const Character&) = delete; // delete copy assignment operator
            Character(Character&&) = delete; // delete move constructor
            Character& operator=(Character&&) = delete; // delete move assignment operator

///////////////////////////////////////////////////////////////////////
        

};
}
#endif