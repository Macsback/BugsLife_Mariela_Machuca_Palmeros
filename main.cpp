#include <iostream>
#include <fstream>
#include <utility>

#include "Crawler.h"
#include "Hopper.h"
#include "Bug.h"
using namespace std;

void initiateBugs (ifstream&);
int main() {
 pair p1(1,3);
 Crawler bug1;
 Hopper bug2;
    
   /* ifstream fin("bugs.txt");
    if(fin)                     // ensures the file input stream is opened correctly
    {
        cout << "\nBug:" << endl;
        initiateBugs( fin );// creates a variable to store each word we read in from the file.
    }
    else
    {
        cout << "Unable to open file" <<endl;
    }
    fin.close();
    */
    return 0;


}

/*void initiateBugs (ifstream & ifstream1 ) {
    char separator;
    char type;
    int id;
    int x;
    int y;
    int direction;
    int size;
    int hopLength;

    while(!ifstream1.eof())     // while not at end of file
    {


        ifstream1 >> type >> separator >> id >> separator;
      cout << separator << endl;


    }
}*/


