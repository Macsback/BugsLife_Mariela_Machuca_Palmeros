//
// Created by Mariela Machuca Palmeros on 18/04/2024.
//

#ifndef BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_HOPPER_H
#define BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_HOPPER_H

#include "Bug.h"

class Hopper: public Bug{
protected:
    int hopLength;

    void move();


public:
    Hopper(int id, int x, int y, int direction, int size, char type, int hopLength);
};
#endif //BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_HOPPER_H
