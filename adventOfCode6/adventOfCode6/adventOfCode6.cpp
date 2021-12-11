// adventOfCode6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std::chrono;
using namespace std;


int main()
{
    const int DAYS = 256;
    unsigned long long int lanternfishCount[7] = { 0,0,0,0,0,0,0 };
    unsigned long long int babylanternCount[7] = { 0,0,0,0,0,0,0};
    int lanternfishDay[7] = { 0,1,2,3,4,5,6 };
    int babylanternDay[7] = { 0,0,0,0,0,0,0 };
    int lanternfishSpawn[7] = { 2,3,4,5,6,0,1 };
    unsigned long long int totalFish = 0;
    auto start = high_resolution_clock::now();
    

    string inputData;
    
    ifstream inputFile;
    inputFile.open("input.txt");
    inputFile >> inputData;
   
    for (int i = 0; i < inputData.length(); i += 2)
    {
        lanternfishCount[static_cast<int>(inputData[i])-48]++;
    }
    
    inputFile.close();
    
    for (int i = 0; i < DAYS; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            
        if (lanternfishDay[j] == 0)
            {
                lanternfishDay[j] = 6;
                babylanternCount[lanternfishSpawn[j]]+=lanternfishCount[j];
                babylanternDay[lanternfishSpawn[j]] = 2;
            }
            else {
                lanternfishDay[j]--;
            }

            if (babylanternDay[j] == 0) {
                lanternfishCount[j] += babylanternCount[j];
                babylanternCount[j] = 0;
            }
            else {
                babylanternDay[j]--;
            }
        }
        
    }

    for (int i = 0; i < 7; i++)
    {
        totalFish += lanternfishCount[i] + babylanternCount[i];
    }

    cout << totalFish << endl;
    auto stop = high_resolution_clock::now();
    // Subtract stop and start timepoints and
// cast it to required unit. Predefined units
// are nanoseconds, microseconds, milliseconds,
// seconds, minutes, hours. Use duration_cast()
// function.
    auto duration = duration_cast<microseconds>(stop - start);

    // To get the value of duration use the count()
    // member function on the duration object
    cout << duration.count() << endl;


    return 0;
}


