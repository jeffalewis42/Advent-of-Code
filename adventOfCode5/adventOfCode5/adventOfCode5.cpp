// adventOfCode5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;


int max(int, int);
int min(int, int);
int stringToInt(string, int, int);
int findNextCommaPlace(string, int);

int main()
{
    string entryFromFile;
    int *diagramPtr=nullptr;
    int count=0;

    diagramPtr = new int[1000000];
    
    for (int i = 0; i <= 999999; i++)
    {
        diagramPtr[i] = 0;
    }

    ifstream inputFile;
    inputFile.open("input.txt");
    if (inputFile.fail())
    {
        cout << "Error opening input file!" << endl;
    }
    else 
    {
    while (inputFile >> entryFromFile)//beginning coordinates is taken here
    {
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

        //convert the string to two integers
        x1 = stringToInt(entryFromFile, 0, findNextCommaPlace(entryFromFile, 0) - 1);
        y1 = stringToInt(entryFromFile, findNextCommaPlace(entryFromFile, 0) + 1, entryFromFile.length()-1);
        
        inputFile >> entryFromFile;//just to get rid of the '--->'
        
        inputFile >> entryFromFile;//ending coordinates
        
        //convert the string to two integers
        x2 = stringToInt(entryFromFile, 0, findNextCommaPlace(entryFromFile, 0) - 1);
        y2 = stringToInt(entryFromFile, findNextCommaPlace(entryFromFile, 0) + 1, entryFromFile.length()-1);


        if (x1 == x2)//vertical line
        {
            int row = x1;
            for (int col = min(y1, y2); col <= max(y1, y2); col++)
            {
                diagramPtr[row * 1000 + col]++;
                if (diagramPtr[row * 1000 + col] == 2)
                {
                    count++;
                }
            }
        }

        else if (y1 == y2)//horizontal line
        {
            int col = y1;
            for (int row = min(x1, x2); row <= max(x1, x2); row++)
            {
                diagramPtr[row * 1000 + col]++;
                if (diagramPtr[row * 1000 + col] == 2)
                {
                    count++;
                }
            }
        }

        else if ((x1<x2&&y1<y2)||(x2<x1&&y2<y1))//diagonal with positive slope...just comment out for first part of problem
        {
            
            for (int row = min(x1, x2), col = min(y1, y2); row <= max(x1, x2); row++, col++)
            {
                diagramPtr[row * 1000 + col]++;
                if (diagramPtr[row * 1000 + col] == 2)
                {
                    count++;
                }
            }            
        }
        else //diagonal with negative slope...just comment out for first part of problem
        {
            for (int row = min(x1, x2), col = max(y1, y2); row <= max(x1, x2); row++, col--)
            {
                diagramPtr[row * 1000 + col]++;
                if (diagramPtr[row * 1000 + col] == 2)
                {
                    count++;
                }
            }            
        }
   }
   }

    inputFile.close();
    cout << count << endl;
    delete [] diagramPtr;
    diagramPtr = nullptr;
    
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
    return 0;
}

int stringToInt(string intString, int beginPlace, int endPlace)
{
    int value = 0, digitPower=0;
    for (int i = endPlace; i >= beginPlace; i--)
    {
        value += ((static_cast<int>(intString[i])) - 48) * pow(10.0, static_cast<double>(digitPower));
        digitPower++;
    }
    return value;
}


int max(int numOne, int numTwo)
{
    if (numOne > numTwo)
        return numOne;
    return numTwo;
}

int min(int numOne, int numTwo)
{
    if (numOne > numTwo)
        return numTwo;
    return numOne;
}