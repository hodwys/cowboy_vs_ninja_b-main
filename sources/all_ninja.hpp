#ifndef ALL_NINJA_HPP
#define ALL_NINJA_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Character.hpp"
using namespace std;
namespace ariel{

class all_ninja : public Character{

    int speed;

    public:
        all_ninja(const string& nam, const Point& loca, int target , int speed);
        void move(Character * malo);
        void slash(Character * malo); 
        int get_speed();
        string print() override;
};
}
#endif