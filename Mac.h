//
// Created by Mariela Machuca Palmeros on 26/04/2024.
//

#ifndef BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_MAC_H
#define BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_MAC_H

#include "Bug.h"

class Mac: public Bug {
protected:

    void move();

public:
    Mac(int id, int x, int y, int direction, int size, char type);
};


#endif //BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_MAC_H
