#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <vector>
#include <numeric>
#include<limits>
#include "Character.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
#include "all_ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"


using namespace std;

namespace ariel{

class Team{

    Character* head_team;
    vector<Character*> team;

    public:
        Team(Character *lead);
        virtual void add(Character * fr_team);
        virtual void attack(Team * other);
        int stillAlive() const;
        void print(); 
        void cheng_lead();
        void set_lead( Character * new_lead);
        Character * find_enemy(Team * other);
        vector<Character*>& get_team();
        virtual ~Team();
        Character * get_lead();


       // virtual ~Team();
       //////////////////////////////////////////////
        Team(const Team& other);
        Team& operator=(const Team& other);
        Team& operator=(Team&& other) = default;
        Team(Team&& other) = default;
        /////////////////////////////////////////////



    
};
}




#endif