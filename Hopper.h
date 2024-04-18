//
// Created by Mariela Machuca Palmeros on 18/04/2024.
//

#ifndef BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_HOPPER_H
#define BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_HOPPER_H

#include "Bug.h"

class Hopper: public Bug{
private:
    int hopLength;

    void move();
};
#endif //BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_HOPPER_H
