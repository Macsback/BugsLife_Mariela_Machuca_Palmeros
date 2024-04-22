//
// Created by Mariela Machuca Palmeros on 11/04/2024.
//

#include "Bug.h"
#include<iostream>

using namespace std;

bool Bug::isWayBlocked() {
// 1.- North 2.- East (right) 3.- South 4.- West (Left)
// Position(X,Y)

    //North
    if(position.second== 0 && direction == 1){
        return true;
    }

    //East
    if(position.first== 10 && direction == 2){
        return true;
    }

    //South
    if(position.second== 10 && direction == 3){
        return true;
    }

    //West
    if(position.first== 0 && direction == 4){
        return true;
    }

        return false;

}


bool Bug::isAlive(){
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
void Bug::addToPath(int x, int y) {
    path.push_back(make_pair(x,y));
}