//
// Created by Mariela Machuca Palmeros on 26/04/2024.
//

#ifndef BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_CELL_H
#define BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_CELL_H
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include <vector>

class Cell {
protected:
    std::vector<Bug*> bugInCell;
};
#endif //BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_CELL_H
