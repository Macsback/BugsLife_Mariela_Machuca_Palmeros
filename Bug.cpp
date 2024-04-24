//
// Created by Mariela Machuca Palmeros on 11/04/2024.
//

#include "Bug.h"
#include<iostream>

using namespace std;

Bug::Bug(int id, int x, int y, int direction, int size, char type)
        : id(id),position(make_pair(x,y)),direction(direction), size(size), alive(true), type(type) {}


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
void Bug::addToPath(int x, int y) {
    path.push_back(make_pair(x,y));
}