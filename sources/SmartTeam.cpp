
#include "SmartTeam.hpp"


using namespace std;

namespace ariel{


SmartTeam ::SmartTeam(Character *lead):Team(lead){}



Character * SmartTeam::find_best_enemy(Team * other , Character* cur , int type){

    double prio = std::numeric_limits<double>::max();
    Character* beast_enemy = nullptr;

    double prio_cow = std::numeric_limits<double>::max();
    
    double prio_nin = std::numeric_limits<double>::max();


    for(Character * enemy : other->get_team()){
         // if i cowboy
        if(type ==0){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(cur);

            if(cowboy->hasboolets()){
                prio_cow = (enemy->getTarget() /10);
                if(prio_cow<prio){
                    prio = prio_cow;
                    beast_enemy = enemy; 
                }
            }
            else{
                cowboy->reload();
            continue;
            }      
        }
    

        // if i nunja
        else{
            all_ninja* ninja = dynamic_cast<all_ninja*>(cur);
            Point cur_Point = cur->getLocation();
            if(enemy->getLocation().distance(cur_Point) <=1){
                prio_nin = 0 + (enemy->getTarget()/ 40);
                if(prio_nin < prio){
                    prio = prio_nin;
                    beast_enemy = enemy; 
                }
            }
            else{
                prio_nin = (((enemy->getLocation().distance(cur_Point)/ ninja->get_speed()) + (enemy->getTarget() )/ 40));
                if(prio_nin < prio){
                    prio = prio_nin;
                    beast_enemy = enemy;
                }
            }
        }
    }


    if( beast_enemy == nullptr || !beast_enemy->isAlive()){
        cout << "mTn ia kinf" << endl;
        return nullptr;
    }

    return beast_enemy;
}



    void SmartTeam:: attack(Team * other){

        if(other == nullptr){
            throw runtime_error("nullptr pointer- smartteam");
        }
        if(other->stillAlive()<=0 || this->stillAlive()<=0){
            throw runtime_error("team is not alive");
        }
        if(this->get_lead() == nullptr || !this->get_lead()->isAlive()){
                this->cheng_lead();
        }

        Character * enemy_to_attak = nullptr;


        for(Character* curr :  this->get_team()){
            if(curr != nullptr && curr->isAlive()){
                int type = 100;
                Cowboy* cowboy = dynamic_cast<Cowboy*>(curr);
                    if(cowboy != nullptr){
                        type=0;
                    }
                    else{
                        type =1;
                    }


                enemy_to_attak= find_best_enemy(other , curr ,type);

                if(enemy_to_attak == nullptr || !enemy_to_attak->isAlive()){
                    if(other->stillAlive() == 0){
                        return;
                    }
                    enemy_to_attak= find_best_enemy(other , curr ,type);
                }
                

                if(type == 0){

                    if(cowboy->hasboolets()){
                        cowboy->shoot(enemy_to_attak); 
                    }
                    else{
                        cowboy->reload(); 
                    }
                }
                else{
                    all_ninja* ninja = dynamic_cast<all_ninja*>(curr);

                    if(ninja->getLocation().distance(enemy_to_attak->getLocation())<1){
                        ninja->slash(enemy_to_attak);
                    }
                    else{
                                
                        ninja->move(enemy_to_attak);
                    }
                }
            }
        }   
    }
}
