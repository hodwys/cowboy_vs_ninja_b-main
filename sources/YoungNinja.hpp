#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "all_ninja.hpp"
using namespace std;

//using namespace ariel;
namespace ariel{

class YoungNinja : public all_ninja{
    int balls;
    public:
        YoungNinja(string nam, Point poin);

    };
}

#endif