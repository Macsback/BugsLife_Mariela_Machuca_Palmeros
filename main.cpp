#include <iostream>
#include <fstream>
#include <utility>
#include <string>       // getline(), stoi(), stod()
#include <sstream>      // string stream
#include "Crawler.h"
#include "Hopper.h"
#include "Bug.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
using namespace std;

void initiateBugs (ifstream&);
void menu(Board&);
int main() {
    Board board;

    board.initializeBug();
    board.displayAllCells();
    menu(board);
int selection;
/*

    board.displayAllBugs();
    cout << endl;
    board.tap();
    board.displayAllBugs();
    cout << endl;
    board.tap();
    board.displayAllBugs();
    cout << endl;
    board.tap();
    board.displayAllBugs();
    board.findBug();
  //board.displayAllCells();

*/



    return 0;


}

void menu(Board& board){
    int request;

    bool exit = false;


    while(!exit) {

        cout << "What would you like to do?" << endl;
        cout << "1. Display All Bugs" << endl;
        cout << "2. Find a Bug" << endl;
        cout << "3. Tap the Bug Board" << endl;
        cout << "4. Display Life History of all bugs" << endl;
        cout << "5. Display all Cells" << endl;
        cout << "6. Run Simulation" << endl;
        cout << "7. Exit" << endl;

        cin>> request;
        switch (request) {
            case 1:
                board.displayAllBugs();
                break;
            case 2:
                board.findBug();
                break;
            case 3:
                board.tap();
                break;
            case 4:
                cout<< "not finished"<< endl;
                board.displayLifeHistory();
                break;
            case 5:
                board.displayAllCells();
                break;
            case 6:
                cout<< "not finished"<< endl;
                break;
            case 7:
                board.exit();
                exit = true;
                break;

        }
    }
};

//TODO Implement a GUI


