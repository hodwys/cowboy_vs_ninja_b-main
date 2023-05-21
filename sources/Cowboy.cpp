
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Character.hpp"
#include "Cowboy.hpp"
using namespace std;
namespace ariel{

//using namespace ariel;


        Cowboy::Cowboy(const string &nam,const Point& poin) : Character(nam,poin, 110),balls(6){
        }


        int Cowboy::getBullet(){
            return this->balls;
        }

        void Cowboy::shoot(Character * malo){
            if(malo == nullptr){
                throw std::runtime_error("hgch");

            }
            if(this != malo){
                if(this->isAlive() && malo->isAlive()){
                    if(this->getBullet()>0){
                        this->balls--;
                        malo->Set_target (malo->getTarget()-10);
                    }
                }else{
                    throw std::runtime_error("gfhfgh");
                }
            }
            else{
                throw std::runtime_error("tdfgdf");
            }
        }


        bool Cowboy::hasboolets(){
            if(this->balls >0){
                return true;
            }
            else{
                return false;
            }
        }


        void Cowboy::reload(){

            if(!this->isAlive()){
                throw std::runtime_error("strdfd");
            }
            else{
            this->balls= 6; 
            }        
        }
        

        string Cowboy::print(){
            string s ="C ";
            if(this->isAlive()){
                s+= this->getName();
                s+= to_string(this->getTarget());
            }
            else{
                s+= "(" + this->getName() + ")";
            }
            s+= this->getLocation().print();
            return s;
        }

}