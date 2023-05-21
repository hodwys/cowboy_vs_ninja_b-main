#ifndef TEAM2
#define TEAM2

#include "Team.hpp"

using namespace std;

namespace ariel{


class Team2 : public Team{


    public:
       Team2(Character *lead);
       void add(Character* add_team) override;
};

}
#endif