//
// Created by Mariela Machuca Palmeros on 26/04/2024.
//

#include "Mac.h"

#include <cstdlib>
#include <iostream>
using namespace std;

Mac::Mac(int id, int x, int y, int direction, int size, char type)
        : Bug(id,x,y,direction,size, type)
{

}

void Mac::move(){
// 1.- North 2.- East (right) 3.- South 4.- West (Left)
if(isAlive()){
    if(isWayBlocked())
    {
        Death();
    }
    else{
    switch (direction) {
        case 1: //North moves in Y up (Less)
            position.second = position.second -1;
            break;
        case 2: //East moves in X right (more)
            position.first = position.first +1;
            break;
        case 3: //South moves in Y down (more)
            position.second = position.second +1;
            break;
        case 4: //West moves in X left (less)
            position.first = position.first -1;
            break;
    }
    addToPath(getPosition().first, getPosition().second);}
}}