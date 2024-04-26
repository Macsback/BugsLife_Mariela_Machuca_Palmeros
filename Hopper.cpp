//
// Created by Mariela Machuca Palmeros on 18/04/2024.
//
#include "Hopper.h"
#include <iostream>
using namespace std;


Hopper::Hopper(int id, int x, int y, int direction, int size, char type, int hopLength)
        : Bug(id, x, y, direction, size, type), hopLength(hopLength)
{

}
void Hopper::move(){
// 1.- North 2.- East (right) 3.- South 4.- West (Left)
    while(isWayBlocked())
    {
        direction = (rand()%4)+1;
    }
        switch (direction) {
            case 1: //North moves in Y up (Less)
                position.second = position.second -hopLength;
                position.second = position.second<0?0:position.second;
                break;
            case 2: //East moves in X right (more)
                position.first = position.first +hopLength;
                position.first = position.first>9?9:position.first;
                break;
            case 3: //South moves in Y down (more)
                position.second = position.second +hopLength;
                position.second = position.second>9?9:position.second;
                break;
            case 4: //West moves in X left (less)
                position.first = position.first -hopLength;
                position.first = position.first<0?0:position.first;
                break;
        }

    addToPath(getPosition().first, getPosition().second);
    }



/*

bool Hopper::isWayBlocked() {
// 1.- North 2.- East (right) 3.- South 4.- West (Left)
// Position(X,Y)
// Check that the hop doesn't go further than the borders
    switch (hopLength) {
        case 2:
            //North
            if(position.second<= 1 && direction == 1){

                return true;
            }

            //East
            if(position.first>= 8 && direction == 2){
                return true;
            }

            //South
            if(position.second>= 8 && direction == 3){
                return true;
            }

            //West
            if(position.first<= 2 && direction == 4){
                return true;
            }
            break;
        case 3:
            //North
            if(position.second<= 3 && direction == 1){

                return true;
            }

            //East
            if(position.first>= 7 && direction == 2){
                return true;
            }

            //South
            if(position.second>= 7 && direction == 3){
                return true;
            }

            //West
            if(position.first<= 3 && direction == 4){
                return true;
            }
            break;

        case 4:
            //North
            if(position.second<= 4 && direction == 1){

                return true;
            }

            //East
            if(position.first>= 6 && direction == 2){
                return true;
            }

            //South
            if(position.second>= 6 && direction == 3){
                return true;
            }

            //West
            if(position.first<= 4 && direction == 4){
                return true;
            }
            break;
    }


    return false;

}*/