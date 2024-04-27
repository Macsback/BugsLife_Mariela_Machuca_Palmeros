//
// Created by Mariela Machuca Palmeros on 23/04/2024.
//

#ifndef BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_BOARD_H
#define BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_BOARD_H

#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Mac.h"
#include <vector>
#include <map>

class Board {

protected:
    std::vector<Bug*> bugVector;
    std::map<std::pair<int,int>, std::vector<Bug*>> cells;

public:
    void parseLine(const std::string& strLine);

    void initializeBug();
    void read_line_by_line(std::ifstream&);
    void displayAllBugs();
    void displayAllCells();
    void updateCells();
    void findBug();
    void displayLifeHistory();
    void exit();
   void playGame();
    void tap();

    Board();


};
#endif //BUGSLIFE_CA2_MARIELA_MACHUCA_PALMEROS_BOARD_H
