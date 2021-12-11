// adventOfCode2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string command;
    int move, horizontal=0, depth=0, aim=0;
    
    ifstream inputFile;
    inputFile.open("input.txt");

    while (inputFile >> command)
    {
        inputFile >> move;
        if (command == "forward")
        {
            horizontal += move;
            depth += move * aim;
        }
        else if(command == "down")
        {
            aim += move;
        }
        else if (command == "up")
        {
            aim -= move;
        }

    }
    inputFile.close();
    cout << "Horizontal Position: " << horizontal << endl;
    cout << "Depth Position: " << depth << endl;
    cout << "Multiplied: " << horizontal * depth << endl;

    return 0;
}

