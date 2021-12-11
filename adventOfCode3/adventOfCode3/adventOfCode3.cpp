// adventOfCode3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    const int SIZE = 12;
    int countOne=0, countZero=0,epsilonRate[SIZE], gammaRate[SIZE], epsilon=0, gamma=0;
    string dataEntry, dataTest;
    vector <string> datum;
    
    
    ifstream inputFile;
    inputFile.open("input.txt");
    
    while (inputFile >> dataEntry)
        datum.push_back(dataEntry);
    inputFile.close();
    
    
    for (int i = 0; i < SIZE; i++)
    {
        countOne = 0;
        countZero = 0;
        
        for (int j = 0; j < datum.size(); j++)
        {
            dataTest = datum[j];
            if (dataTest[i] == '0')
                countZero++;
            else
                countOne++;
        }
        if (countOne > countZero) 
        {
            gammaRate[11 - i] = 1;
            epsilonRate[11 - i] = 0;
        }
        else
        {
            gammaRate[11 - i] = 0;
            epsilonRate[11 - i] = 1;
        }
            }
    cout << "Gamma Rate: ";
    for (int k = SIZE - 1; k >= 0; k--)
    {
        cout << gammaRate[k];
        gamma += gammaRate[k] * pow(2.0, static_cast<double>(k));
    }
    cout << " = " << gamma << endl;
    
    cout << "Epsilon Rate: ";
    for (int l = SIZE - 1; l >= 0; l--)
    {
        cout << epsilonRate[l];
        epsilon += epsilonRate[l] * pow(2.0, static_cast<double>(l));
    }
    cout << " = " << epsilon << endl;
    cout << "Power Consumption: " << gamma * epsilon << endl;

    return 0;
}

