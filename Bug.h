//
// Created by Mariela Machuca Palmeros on 11/04/2024.
//

#ifndef BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_BUG_H
#define BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_BUG_H
#include <utility>
#include <list>

class Bug {
protected:
    int id;  // member data
    std::pair<int, int> position;
    int direction;
    int size;
    bool alive;
    std::list<std::pair<int,int>>;

    virtual void move() =0;
    bool isWayBlocked();
};
#endif //BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_BUG_H
