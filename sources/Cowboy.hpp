#ifndef COWBOY
#define COWBOY

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Character.hpp"
#include "Point.hpp"

using namespace std;
namespace ariel{
class Cowboy : public Character{

    int balls;

    public:
   
        Cowboy(const string& nam,const Point& poin);
        int getBullet();
        void shoot(Character * malo);
        bool hasboolets();
        void reload();
        string print() override;
};
}
#endif