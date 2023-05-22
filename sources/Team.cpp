
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <limits>
#include <cmath>

#include "Team.hpp"
using namespace std;

namespace ariel{

    Team::Team(Character *lead): head_team(lead) {

        if(lead == nullptr){
            throw std::runtime_error("423435");
        }

        if(lead->get_in_team()){
            throw std::runtime_error("player is already in a team");
        }
        if(lead->isAlive()==0){
            throw std::runtime_error("player is already in a team");
        }
        this->team.push_back(lead);
        lead->set_in_team(true);  
    }


    Character* Team::find_enemy(Team * other){
    if(other== nullptr){
        throw std::runtime_error("player is already in a team");
    }
    double min= std::numeric_limits<double>::max();
    Character * malo= nullptr;
    double dis=0;
    for(Character *abc: other->team ){
        if(abc== nullptr){
            throw std::runtime_error("player is already");
        }
        if(abc->isAlive()){
            dis= (this->head_team->distance(abc));
                if(dis<min){
                    min = dis;
                    malo=abc; 
                }
        }
    }
      if(malo->isAlive()==0){
        throw std::runtime_error("enemy daeylready"); 
      }   
        return malo;
    }
    void Team::set_lead( Character * new_lead){
        this->head_team = new_lead;
    }

    
    void Team::cheng_lead(){
        if(this->stillAlive() == 0){return;}
        double min = std::numeric_limits<double>::max();
        Character * new_lead = nullptr;
        double dis=0;
        for(Character *hod : team ){
            if(hod->isAlive()){
                dis= (hod->distance(this->head_team));
                if(dis<min){
                    min = dis;
                    new_lead =hod; 
                }
            }
        }
        if(new_lead->isAlive()==0){
            throw std::runtime_error("player is already in a team");   
        }
        set_lead(new_lead);

    }

    void Team::add(Character *add_team){
        if(add_team == nullptr){
            throw std::runtime_error("tdfgf");
        }
        if(!(add_team->isAlive())){
            throw std::runtime_error("tdfgf");
        }
        if( add_team->get_in_team()){
            throw std::runtime_error("tdfgf");
        }
            if(team.size()<10){
                if(Cowboy* cowboy = dynamic_cast<Cowboy*>(add_team)){
                    team.insert(team.begin(),add_team);
                }
                else{
                    team.push_back(add_team);
                }
                //team.push_back(add_team);
                add_team->set_in_team(true);
            }
            else{
                throw runtime_error("the team already 10 player");
            }
        }
    

    int Team::stillAlive() const{
        int count = 0;
        for(auto player : team){
          if(player->isAlive()){
            count++;
          }  
        }
        return count;
    }


    void Team::print(){
        for(size_t i=0; i<team.size()-1; i++){

            cout<<team[i]->print() +", "<<endl;
        }  
            cout<<team[team.size()-1]->print()<<endl;
    }


void Team::attack(Team * other){

    if(other == nullptr || head_team == nullptr){
        throw std::invalid_argument("asfdgdf");
    }
    
    if(this->stillAlive()==0){
        return;
    }
    if(!(other->stillAlive()> 0)){
        throw std::runtime_error("jhhjvkdf");
    }
    if(!(head_team->isAlive())){
        cheng_lead();
    }
       
    Character* enemy = find_enemy(other);

    for(Character* abc: this->team ){

        if(!enemy->isAlive()){
            if(other->stillAlive() == 0){
                return;
            }
            enemy = find_enemy(other);
        }
        
        if(abc->isAlive()){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(abc);
            if(cowboy != nullptr){

                if(cowboy->hasboolets()){
                    cowboy->shoot(enemy); 
                }
                else{
                    cowboy->reload(); 
                }
            }
            else{
                all_ninja* ninja = dynamic_cast<all_ninja*>(abc);
                if(ninja->getLocation().distance(enemy->getLocation())<1){
                    ninja->slash(enemy);
                }
                else{
                        
                    ninja->move(enemy);
                    }
                }
            
            }
    }
}

vector<Character*>& Team::get_team(){
    return this->team;
}

Character* Team:: get_lead(){
    return this->head_team;
}
////////////////////////////////////////////////
Team::~Team(){
    for(Character * abc :team){
        delete abc;
    }
}


    Team::Team(const Team& other) : head_team(other.head_team){
            // Copy the state of the `other` object
            // to the new `Team` object
            // ...
    }

    Team& Team::operator=(const Team& other) {
        if (this != &other) {
            // Copy the state of the `other` object
            // to the current object
            // ...
        }
        return *this;
    }



//////////////////////////////////////////
///דיסקטרטור
}

