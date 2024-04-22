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
    std::list<std::pair<int,int>> path;


    //Constructor
    Bug(int id, int x, int y, int direction, int size);

int getId() const;
void setId(int id);

std::pair<int, int> getPosition() const;
void setPosition(const std::pair<int, int> &position);

int getDirection() const;
void setDirection(int direction);

int getSize() const;
void setSize(int size);

/*bool isAlive() const;
*/
void setAlive(bool alive);

std::list<std::pair<int, int>> getPath() const;
void addToPath(int x, int y);

virtual void move() =0;
bool isWayBlocked();
    bool isAlive();
    void Death();
};
#endif //BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_BUG_H
