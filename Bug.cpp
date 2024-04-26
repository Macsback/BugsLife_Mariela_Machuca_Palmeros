//
// Created by Mariela Machuca Palmeros on 11/04/2024.
//

#include "Bug.h"
#include<iostream>

using namespace std;

Bug::Bug(int id, int x, int y, int direction, int size, char type)
        : id(id),position(make_pair(x,y)),direction(direction), size(size), alive(true), type(type) {}


bool Bug::isAlive() const{
    return alive;
}

void Bug::Death() {
    this->alive = false;
}


//id
int Bug::getId() const {
    return id;
}
void Bug::setId(int id) {
    this ->id = id;
}

//Position
pair<int, int> Bug::getPosition() const
{
    return position;
}
void Bug::setPosition(const pair<int, int> &position) {
    this -> position = position;
}

//Direction
int Bug::getDirection() const {
    return direction;
}
void Bug::setDirection(int direction) {
    this -> direction = direction;
}

//Size
int Bug::getSize() const {
    return size;
}
void Bug::setSize(int size) {
    this ->size = size;
}


//Type

char Bug::getType() const
{
    return type;
}

/*bool Bug::isAlive() const {
    return alive;
}
*/

/*void Bug::setAlive(bool alive) {
    this->alive = alive;
}*/

//Path
list<pair<int, int>> Bug::getPath() const {
    return path;
}
bool Bug::isWayBlocked() {

// 1.- North 2.- East (right) 3.- South 4.- West (Left)
// Position(X,Y)

    //North
    if(position.second== 0 && direction == 1){
        return true;
    }

    //East
    if(position.first== 9 && direction == 2){
        return true;
    }

    //South
    if(position.second== 9 && direction == 3){
        return true;
    }

    //West
    if(position.first== 0 && direction == 4){
        return true;
    }

    return false;
}
void Bug::addToPath(int x, int y) {
    path.push_back(make_pair(x,y));
}

/*bool Bug::operator== (Bug const& bug2) const{
    cout<<"is working";
    if(this->getPosition() == bug2.getPosition())
    {
        return true;
    }
    else
    {
        return false;
    }
}*/

void Bug::eat(Bug *bug2) {

//cout<<"eat was triggered";
    if(bug2->isAlive()){
        //cout<< "Compare alive: Works!"<< endl;
        int bug1Size = getSize();
        int bug2Size = 3;
        if(bug1Size > bug2Size){
            bug2->Death();
           // if(!bug2->isAlive()){
               // cout<<"Bug is dead";
          //  }

           bug1Size = bug1Size+bug2Size;
           setSize(bug1Size);
        } else{
            Death();
        }
    }
}