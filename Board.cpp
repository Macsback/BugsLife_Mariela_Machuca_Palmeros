//
// Created by Mariela Machuca Palmeros on 23/04/2024.
//


#include "Board.h"
#include "Bug.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace std;
Board::Board()
{

}

void Board::initializeBug()
{
    cout << "Attempting to read from a comma-delimited text file." << endl;

    ifstream inFileStream("bugs.txt"); // open file as input file stream (from working directory)

    if ( inFileStream.good() )  // if file opened successfully, and not empty
    {
        string line;            // create a string object to store a line of text

        while ( getline(inFileStream, line) )   // read a line until false returned , getline() from <string> library
        {
            parseLine( line );  // pass the line of text to have it parsed
        }
        inFileStream.close();
    }
    else
        cout << "Unable to open file, or file is empty.";
}

void Board::parseLine(const string& strLine){

 /*   // turn the line of text into a stringstream for tokenizing
    stringstream strStream( strLine );

    // set the delimiter character that is used in teh file (i.e. what separates the tokens in the string)
    // This could be a semicolon, or any character that we choose
    const  char DELIMITER = ';';
    string name;
    // extract the first token (the name) into the name variable
    // - a comma delimits the strings  -
    getline(strStream, name, DELIMITER);

    int age = 0;
    double height = 0.0;

    try
    {
        string strTemp;
        getline(strStream, strTemp, DELIMITER);  // read next field (age) as a string
        age = stoi(strTemp);    // convert string to int conversion (may throw exceptions)

        getline(strStream, strTemp, DELIMITER);   // extract the height as a string
        height = stod(strTemp); // convert string to double (may throw exceptions)
    }
    catch (std::invalid_argument const& e)
    {
        cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const& e)
    {
        cout << "Integer overflow: std::out_of_range thrown" << '\n';
    }
    cout << "Name: " << name << " age: " << age << " height: " << height << endl;*/

 // turn the line of text into a stringstream for tokenizing
 stringstream strStream( strLine );

 // set the delimiter character that is used in teh file (i.e. what separates the tokens in the string)
 // This could be a semicolon, or any character that we choose
 const  char DELIMITER = ';';
 string strTemp;
 string type;
 int id, x, y, size, direction;
  int  hopLength = 0;
 // extract the first token (the name) into the name variable
 // - a comma delimits the strings  -
 getline(strStream, type, ';');
 //cout << type << "type";

 int length = type.length();
 char* char_array = new char[length + 1];

 try
 {
     string strTemp;
     getline(strStream, strTemp, DELIMITER);  // read next field (age) as a string
     id = stoi(strTemp);    // convert string to int conversion (may throw exceptions)

     getline(strStream, strTemp, DELIMITER);   // extract the height as a string
     x = stoi(strTemp); // convert string to double (may throw exceptions)
 }
 catch (invalid_argument const& e)
 {
     cout << "Bad input: std::invalid_argument thrown" << '\n';
 }
 catch (out_of_range const& e)
 {
     cout << "Integer overflow: std::out_of_range thrown" << '\n';
 }



 strcpy(char_array, type.c_str());
 getline(strStream, strTemp, DELIMITER);  // read next field (age) as a string
y = stoi(strTemp);
 getline(strStream, strTemp, DELIMITER);  // read next field (age) as a string
    direction = stoi(strTemp);
 getline(strStream, strTemp, DELIMITER);  // read next field (age) as a string
 size = stoi(strTemp);
 /*string temDir;
 getline(strStream, temDir, DELIMITER);  // read next field (age) as a string
 cout << temDir << "after reading line";

 getline(strStream, strTemp, DELIMITER);  // read next field (age) as a string
 //size = stoi(strTemp);




 getline(strStream, strTemp, DELIMITER);  // read next field (age) as a string
 //hopLength = stoi(strTemp);

 //direction =3;
*/
 if(type == "C")
 {

     bugVector.push_back(new Crawler(id, x, y, direction, size, char_array[0]));

 }
 else if(type == "H")
 {
     getline(strStream, strTemp, DELIMITER);  // read next field (age) as a string
     hopLength = stoi(strTemp);
     bugVector.push_back(new Hopper(id, x, y, direction, size, char_array[0],hopLength));
 }
 else if(type == "M")
 {

     bugVector.push_back(new Mac(id, x, y, direction, size, char_array[0]));
 }
   // cout << "type: " << type << " id: " << id << " x: " << x << " y: " << y << " direction: " << direction << " hopLength: " << hopLength << endl;

}


void Board::displayAllBugs()
{
    for(Bug* bug : bugVector)
    {
        cout <<  bug->getId();
        if(bug->getType() == 'C')
        {
            cout << " Crawler ";
        }
        else if(bug->getType() =='H')
        {
            cout << " Hopper ";
        }
        else if(bug->getType() =='M')
        {
            cout << " Mac ";
        }
        cout << "(" << bug->getPosition().first << "," << bug->getPosition().second << ") ";
        cout << bug->getSize();
        switch (bug->getDirection())
        {
            case 1:
                cout << " North ";
                break;
            case 2:
                cout << " East ";
                break;
            case 3:
                cout << " South ";
                break;
            case 4:
                cout << " West ";
                break;
        }

        cout << (bug->isAlive() ? "Alive" : "Dead");
        cout << endl;
    }
}

void Board::findBug(){
    int bugId;
    bool bugFound = false;

    cout<<"What Bug are you looking for?"<< endl;
    cin>>bugId;

    for(Bug* bug : bugVector)
    {

        if(bug->getId() == bugId)
        {

       bugFound = true;
            cout <<  bug->getId() << " ";

            if (dynamic_cast<Crawler*>(bug)) {
                cout << "Crawler ";
            } else if (dynamic_cast<Hopper*>(bug)){
                cout << "Hopper ";
            }else{
                cout << "Mac ";
            }
            cout << "(" << bug->getPosition().first << "," << bug->getPosition().second << ") ";
            cout << bug->getSize();
            switch (bug->getDirection())
            {
                case 1:
                    cout << " North ";
                    break;
                case 2:
                    cout << " East ";
                    break;
                case 3:
                    cout << " South ";
                    break;
                case 4:
                    cout << " West ";
                    break;
            }

            cout << (bug->isAlive() ? "Alive" : "Dead");
            cout << endl;
        }

    }
    if(!bugFound)
    {
        cout << "Bug " << bugId << " not found." << endl;
    }
}

void Board::displayAllCells()
{


    updateCells();
    for (int y = 0; y < 10; ++y) //rows
    {
        for (int x = 0; x < 10; ++x) //columns
        {
            pair<int, int> cellCoordinates = make_pair(x, y); //coordinates of the current cell
            cout << "(" << x << "," << y << "): ";

            auto it = cells.find(cellCoordinates);
            //no cell in the map or no bugs in the cell
            if (it == cells.end() || it->second.empty())
            {
                cout << "empty" << endl;
            }
            else
            {
                bool firstBug = true;
                for (Bug *bug: it->second)
                {
                    if (!firstBug)
                    {
                        cout << ", ";
                    }
                    if (dynamic_cast<Crawler*>(bug)) {
                        cout << "Crawler ";
                    } else if (dynamic_cast<Hopper*>(bug)){
                        cout << "Hopper ";
                    }
                    else{
                        cout << "Mac ";
                    }
                    cout << bug->getId() << " ";
                    if(bug->isAlive()){
                        cout<<"Alive";
                    } else{
                        cout<< "Dead";
                    }
                   // cout << (bug->isAlive() ? "Alive" : "Dead");
                    firstBug = false;
                }
                cout << endl;
            }
        }
    }

    /*
    sf::RenderWindow window(
            sf::VideoMode(640, 480),
            "Hello World");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
     */
}
void Board::updateCells()
{
    cells.clear();
    for (Bug *bug: bugVector) {

    pair<int,int> position = bug->getPosition();
    int x = position.first;
    int y = position.second;
    if(bug->isAlive()){
        cells[{x,y}].push_back(bug); }//finds the cell with the key and pushes bug into vector with that key
    }

  /*for (int y = 0; y < 10; ++y) //rows
    {
        for (int x = 0; x < 10; ++x) //columns
        {
            pair<int, int> cellCoordinates = make_pair(x, y);
            for (Bug *bug: bugVector) {
                if (bug->getPosition() == cellCoordinates) {

                }
            }
        }
    }*/
}

void Board::exit() {
    ofstream fout("Output.txt"); // create a file output stream to Output.txt. If the file does not exist create it.
    if(fout) // make sure the file has opened correctly
    {
        for(Bug* bug : bugVector)
        {
            fout <<  bug->getId();
            if(bug->getType() == 'C')
            {
                fout << " Crawler ";
            }
            else if(bug->getType() =='H')
            {
                fout << " Hopper ";
            }
            else if(bug->getType() =='M')
            {
                fout << " Mac ";
            }
            fout << "(" << bug->getPosition().first << "," << bug->getPosition().second << ") ";
            fout << bug->getSize();
            switch (bug->getDirection())
            {
                case 1:
                    fout << " North ";
                    break;
                case 2:
                    fout << " East ";
                    break;
                case 3:
                    fout << " South ";
                    break;
                case 4:
                    fout << " West ";
                    break;
            }

            fout << (bug->isAlive() ? "Alive" : "Dead");
            fout << endl;

            fout<<"life history of bug:"<<endl;
            fout <<  bug->getId();
            if(bug->getType() == 'C')
            {
                fout << " Crawler ";
            }
            else if(bug->getType() =='H')
            {
                fout << " Hopper ";
            }
            else if(bug->getType() =='M')
            {
                fout << " Mac ";
            }


            const list<pair<int, int>> &path = bug->getPath();

            for (auto it = path.begin(); it != path.end(); it++){
                fout << "(" << it->first << "," << it->second << ") ";
            }

            fout << endl;
            fout << endl;
        }
        fout.close(); // close the file when we are finished.
    }
    else
    {
        cout << "Unable to open file." <<endl;
    }
}

void Board::tap()
{
//move Bug
    for(Bug* bug1 : bugVector)
    {
        bug1->move();

    }

    //fight

    vector<Bug*> cellVector;
    for (int y = 0; y < 10; ++y) //rows
    {
        //make pointer for bug2
        for (int x = 0; x < 10; ++x) //columns
        {
           cellVector = cells[{x,y}];
           if(cellVector.size() > 1){
               Bug* bug2 = cellVector[1];
               cellVector[0]->eat(reinterpret_cast<Bug &>(bug2));
           }
        }

    }
    updateCells();
  /*  for(Bug* bug1 : bugVector)
    {
    for(Bug* bug2 : bugVector)
    {

        if(bug1->getPosition() == bug2->getPosition()){
            bug1->eat(reinterpret_cast<Bug &>(bug2));
        }
    }
        }*/
}



void Board::displayLifeHistory()
{
    for(Bug* bug : bugVector)
    {

        cout <<  bug->getId();
        if(bug->getType() == 'C')
        {
            cout << " Crawler ";
        }
        if(bug->getType() =='H')
        {
            cout << " Hopper ";
        }
         if(bug->getType() =='M')
        {
            cout << " Mac ";
        }


        const list<pair<int, int>> &path = bug->getPath();

        for (auto it = path.begin(); it != path.end(); it++){
            cout << "(" << it->first << "," << it->second << ") ";
        }
        cout << endl;
    }
}
