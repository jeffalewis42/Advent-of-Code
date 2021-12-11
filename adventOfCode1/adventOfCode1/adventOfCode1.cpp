// adventOfCode1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

bool isLarger(int, int);


int main()
{
    int oldSum = 0, newSum = 0, count = 0, dataLine = 0, dataIn;
    vector <int> inputData;

    ifstream inputFile;
    inputFile.open("input.txt");

    while (inputFile >> dataIn)
    {
        inputData.push_back(dataIn);
        dataLine++;
    }
    
    oldSum = inputData[0] + inputData[1] + inputData[2];

    for (int i = 1; i + 2 < dataLine; i++)
    {
        newSum = inputData[i] + inputData[i + 1] + inputData[i + 2];
        if (isLarger(oldSum, newSum))
            count++;
        oldSum = newSum;
    }
    
    cout << count << endl;
    inputFile.close();
    return 0;
}

bool isLarger(int old, int newInt)
{
    if (newInt>old)
    {
        return true;
    }
    return false;
}
