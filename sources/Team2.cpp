    #include"Team2.hpp"
    #include"Team.hpp"
    //#include <cmath>
    
    namespace ariel{
    
    Team2::Team2(Character *lead):Team(lead){
    }

    void Team2::add(Character *add_team)
    {
        if(add_team == nullptr){
            throw std::runtime_error("player is already in a team");
        }
        if(add_team->get_in_team()){
            throw std::runtime_error("plיחיחn a team");
        }

            if(get_team().size()<10){

                get_team().push_back(add_team);
                add_team->set_in_team(true);
            }
            else{
                throw runtime_error("the team already 10 player");
            }
        }

    



};