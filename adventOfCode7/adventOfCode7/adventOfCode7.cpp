// adventOfCode7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int stringToInt(string, int, int);
int findNextCommaPlace(string, int);

int main()
{
    string stringDatum;
    int commaStart = 0, commaEnd, inputNum, total=0, average=0, testNumber=0, testTotal, lowerTotal, higherTotal;
    vector <int> number;
    bool lowestFound = false;
    
    ifstream inputFile;
    inputFile.open("input.txt");
    inputFile >> stringDatum;
    inputFile.close();

    do {
        commaEnd = findNextCommaPlace(stringDatum, commaStart);
        if (commaEnd == -1)
        {
            inputNum = stringToInt(stringDatum, commaStart, stringDatum.length()-1);
        }
        else
        {
            inputNum = stringToInt(stringDatum, commaStart, commaEnd-1);
        }
        number.push_back(inputNum);
        commaStart = commaEnd + 1;

    } while (commaEnd != -1);
    
    for (int i = 0; i < number.size(); i++)
    {
        total += number[i];
    }

    average = total / static_cast<double>(number.size());

    testNumber = average;
   while(!lowestFound) {
        testTotal = 0;
        lowerTotal = 0;
        higherTotal = 0;
        for (int i = 0; i<number.size(); i++) {
            
            for (int j = 1; j <= sqrt((testNumber - number[i]) * (testNumber - number[i])); j++) {
                testTotal += j;
            }
            
            for (int j = 1; j <= sqrt((testNumber - number[i] - 1) * (testNumber - number[i] - 1)); j++) {
                lowerTotal += j;
            }
                        
            for (int j = 1; j <= sqrt((testNumber - number[i] + 1) * (testNumber - number[i] + 1)); j++) {
                higherTotal += j;
           }
                        
        }
        if (testTotal < lowerTotal && testTotal < higherTotal)
        {
            lowestFound = true;
        }
        else if (lowerTotal < testTotal) {
            testNumber--;
        }
        else {
            testNumber++;
        }

    }

   cout << testTotal << endl;
return 0;

    }
    



int findNextCommaPlace(string entryString, int start)
{
    for (int i = start; i < entryString.length(); i++)
    {
        if (entryString[i] == ',')
        {
            return i;
        }
    }
    return -1;
}

int stringToInt(string intString, int beginPlace, int endPlace)
{
    int value = 0, digitPower = 0;
    for (int i = endPlace; i >= beginPlace; i--)
    {
        value += ((static_cast<int>(intString[i])) - 48) * pow(10.0, static_cast<double>(digitPower));
        digitPower++;
    }
    return value;
}

