#include "iostream"
#include "iterator"
#include "map"
#include "fstream"
#include "string"

using namespace std;

/*
program is based on the explaination video from the youtuber Veritasium

https://www.youtube.com/watch?v=iSNsgj1OCLA&t=629s

*/

int main()
{

    // file stream to read generated values from the python program
    fstream file;
    file.open("list.txt", ios::in);

    // create a empty map to store all the records
    map<int, int> room;

    // store values from text file to the map
    int counter = 0;
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            room.insert(pair<int, int>(counter, stoi(line)));
            counter++;
        }
    }

    // start cycles
    // consider the prisnored are queued according to their respective number

    return 0;
}
