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
using namespace sf;
void initiateBugs (ifstream&);
void menu(Board&);
void GUI();
void GUICreateGrid();
int main() {
    Board board;
//GUI();
    board.initializeBug();
  board.displayAllCells();
 /*   board.initializeBug();
    board.displayAllCells();
    menu(board);*/

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

void GUI(){
    RenderWindow window(VideoMode(800, 800), "SFML Grid");

    // Define the size of each grid cell
    const float cellSize = 80.0f;

    // Create shapes to represent each type of cell
  RectangleShape cell1(Vector2f(cellSize, cellSize));
    cell1.setFillColor(Color(255, 232, 225));


   RectangleShape cell2(Vector2f(cellSize, cellSize));
    cell2.setFillColor(Color(255,196,209));


    // Main loop
    while (window.isOpen()) {
        // Event handling
        Event evnt;
        while (window.pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw the grid
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                // Alternate between cell1 and cell2 based on the cell position
                RectangleShape& currentCell = ((i + j) % 2 == 0) ? cell1 : cell2;
                // Set the position of the cell
                currentCell.setPosition(i * cellSize, j * cellSize);
                // Draw the cell
                window.draw(currentCell);
            }
        }

        // Display the window
        window.display();
    }


   /* RenderWindow window(VideoMode(800, 800), "Bugs Life", Style::Close | Style::Titlebar);
    RectangleShape player(Vector2f(80,80));
    player.setFillColor(Color(255,232,225));
    while(window.isOpen()){
        Event evnt;
        while(window.pollEvent(evnt)){
            switch (evnt.type) {
                case Event::Closed:
                    window.close();
                    break;
                
            }
        }
       if(Keyboard::isKeyPressed(Keyboard::Key::Right)){
           player.move(0.8,0);
       }
       window.clear();
        window.draw(player);
        window.display();
    }*/

};


//TODO Implement a GUI

//Pretty Pink Color Color(255, 42, 97)
