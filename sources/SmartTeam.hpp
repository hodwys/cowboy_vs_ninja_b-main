#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"

using namespace std;

namespace ariel{


class SmartTeam : public Team{


    public:
        SmartTeam(Character *lead);
        void attack(Team * other) override;
        Character* find_best_enemy(Team * other , Character * cur , int type);

};

}
#endif