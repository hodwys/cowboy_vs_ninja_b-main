
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include "Character.hpp"
#include "Cowboy.hpp"
using namespace std;
namespace ariel{

    Cowboy::Cowboy(const string &nam,const Point& poin) : Character(nam,poin, 110),balls(6){
    }

    int Cowboy::getBullet(){
        return this->balls;
    }

    void Cowboy::shoot(Character * malo){
        if(malo == nullptr){
            throw std::runtime_error("nullptr pointer - shoot");
        }
        if(malo->isAlive()==0){
            throw std::runtime_error("malo is not Alive() - shoot");
        }
        if(this != malo){
            if(this->isAlive()){
                if(this->getBullet()>0){
                    this->balls--;
                    malo->Set_target (malo->getTarget()-10);
                }
            }else{
                throw std::runtime_error("this is not Alive() -shoot");
            }
        }
        else{
            throw std::runtime_error("this == malo - shoot");
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
            throw std::runtime_error("this is not Alive - reload");
        }
        else{
        this->balls= 6; 
        }        
    }
        
    string Cowboy::print(){
        string s ="C ";
        if(this->isAlive()){
            s+= " name: "+ this->getName();
            s+= " target: " + to_string(this->getTarget());
        }
        else{
            s+= " (" + this->getName() + ") ";
        }
        s+= "loc: "+this->getLocation().print();
        return s;
    }

}