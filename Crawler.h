//
// Created by Mariela Machuca Palmeros on 18/04/2024.
//

#ifndef BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_CRAWLER_H
#define BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_CRAWLER_H

#include "Bug.h"

class Crawler: public Bug{

protected:

    void move();

public:
    Crawler(int id, int x, int y, int direction, int size, char type);
};
#endif //BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_CRAWLER_H
