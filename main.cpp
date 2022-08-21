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

void foundMessage(int, int);
void log(int, int, int);

int main()
{
    //results
    int successcount;

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
    for (int i = 0; i < 100; i++)
    {
        // each prisoner will get 50 chances
        int attempts = 1;
        // current reference ( start from the prisoner number)
        int currentref;
        // each prisoner start looking from their own number
        currentref = room.at(i);
        int next;
        bool found = false;
        // log(i, currentref, attempts);
        //cout << i << " :  " << room.at(i) << "\n";
        if (currentref == i)
        {
            // found in the first attempt
            found = true;
            foundMessage(i, 1);
        }
        while (!found)
        {
            // log(i, currentref, attempts);
            if (attempts < 50)
            {
                //cout << i << " :  " << room.at(currentref) << "\n";
                next = room.at(currentref);
                if (next == i)
                {
                    found = true;
                    foundMessage(i, attempts);
                    successcount++;
                    break;
                }
                currentref = next;
            }
            else
            {
                foundMessage(i, 51);
                break;
            }
            attempts++;
        }
    }

    cout << "\n\n-----------------Results-----------------\n" <<
        "Number of Prisoners           : " << 100 <<
        "\nSuccess Rate                  : " << successcount << " %" <<
        "\n-----------------------------------------";
    return 0;
}

void foundMessage(int pid, int attempts)
{
    if (attempts > 50)
    {
        cout << "- Prisoner " << pid << " did not found within 50 attempts\n";
    }
    else {
        cout << "+ Prisoner " << pid << " found in " << attempts << " attempts\n";
    }
}

void log(int pid, int value, int attempts)
{
    cout << "+ Prisoner : " << pid << " Opened : " << value << " Attempts : " << attempts << "\n";
}