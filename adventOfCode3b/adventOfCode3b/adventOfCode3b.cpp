// adventOfCode3b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int binaryStringToInt(string entryString);

int main()
{
    const int SIZE = 12;
    int countOne = 0, countZero = 0;
    string dataEntry, dataTest;
    char criteria;
    vector <string> oxygen;
    vector <string> co2;


    ifstream inputFile;
    inputFile.open("input.txt");
    
    while (inputFile >> dataEntry)
    {
        oxygen.push_back(dataEntry);
        co2.push_back(dataEntry);
    }
    inputFile.close();


    for (int i = 0; i < SIZE; i++)
    {
        countOne = 0;
        countZero = 0;

        for (int j = 0; j < oxygen.size(); j++)//Count the zeros and ones
        {
            dataTest = oxygen[j];
            if (dataTest[i] == '0')
                countZero++;
            else
                countOne++;
        }
        
        if (countOne >= countZero)
        {
            criteria = '1';
        }
        else
        {
            criteria = '0';
        }
               
        if(oxygen.size()>1){
        for (int j = 0; j != oxygen.size();) {
            dataTest = oxygen[j];
            if (dataTest[i]!=criteria) {
                oxygen.erase(oxygen.begin()+j); 
            }
            else {
                j++;
            }
        }
        }
                
    }
   
    for (int i = 0; i < SIZE; i++)
    {
        countOne = 0;
        countZero = 0;

        for (int j = 0; j < co2.size(); j++)
        {
            dataTest = co2[j];
            if (dataTest[i] == '0')
                countZero++;
            else
                countOne++;
        }
        
        if (countOne < countZero)
        {
            criteria = '1';
        }
        else
        {
            criteria = '0';
        }
                
        if(co2.size()>1){
        for (int j = 0; j != co2.size();) {
            dataTest = co2[j];
            if (dataTest[i] != criteria) {
                co2.erase(co2.begin() + j);
            }
            else {
                j++;
            }
        }
        }

    }
    cout << oxygen[0] << " : " << binaryStringToInt(oxygen[0]) << endl;
    cout << co2[0] << " : " << binaryStringToInt(co2[0]) << endl;
    cout << binaryStringToInt(oxygen[0]) * binaryStringToInt(co2[0]) << endl;

    return 0;
}


int binaryStringToInt(string entryString)
{
    int total = 0;
    for (int i = entryString.length() - 1; i >= 0; i--)
    {
        total += (static_cast<int>(entryString[i]) - 48) * pow(2.0, 11-i);
    }
    return total;
}
