//
// Created by Mariela Machuca Palmeros on 18/04/2024.
//

#include "Crawler.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Crawler::Crawler(int id, int x, int y, int direction, int size, char type)
        : Bug(id,x,y,direction,size, type)
{

}
bool Crawler::isWayBlocked() {
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
void Crawler::move(){
// 1.- North 2.- East (right) 3.- South 4.- West (Left)
    if(!isWayBlocked()) {
        switch (direction) {
            case 1: //North moves in Y up (Less)
                position.second = position.second -1;
                break;
            case 2: //East moves in X right (more)
                position.first = position.second +1;
                break;
            case 3: //South moves in Y down (more)
                position.second = position.second +1;
                break;
            case 4: //West moves in X left (less)
                position.first = position.second -1;
                break;
        }
    }
    else{
        setDirection(rand() %4 +1);
    }

    addToPath(getPosition().first, getPosition().second);

}


