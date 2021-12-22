// adventOfCode13.cpp : 
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


using namespace std;

int stringToInt(string, int, int);
int findNextCommaPlace(string, int);

int main()
{
    const int XPOSITIONS = 1311;
    const int YPOSITIONS = 1000;
    const int INSTRUCTIONS = 12;

    string tempEntry;
    int tempX = 0, tempY = 0, count=0, xFold=XPOSITIONS, yFold=YPOSITIONS, fold[INSTRUCTIONS];
    int* diagramPtr = nullptr; 
    char foldType[INSTRUCTIONS];

    diagramPtr = new int[XPOSITIONS*YPOSITIONS];
    
    for (int i = 0; i < (XPOSITIONS*YPOSITIONS); i++)
    {
        diagramPtr[i] = 0;
    }
    
    
    //Get the dot positions

    ifstream inputFile;
    inputFile.open("input.txt");
    for (int i = 0; i < 715; i++) {
        inputFile >> tempEntry;
        int commaplace = findNextCommaPlace(tempEntry, 0);

        tempX = stringToInt(tempEntry, 0, findNextCommaPlace(tempEntry, 0) - 1);
        tempY = stringToInt(tempEntry, findNextCommaPlace(tempEntry, 0) + 1, tempEntry.length() - 1);
        diagramPtr[tempX * 1000 + tempY] = 1;

    }
    getline(inputFile, tempEntry);
    getline(inputFile, tempEntry);

    for (int i = 0; i < 12; i++) {
        getline(inputFile, tempEntry);
        foldType[i] = tempEntry[11];
        fold[i] = stringToInt(tempEntry, 13, tempEntry.length() - 1);
    }
    
   

    inputFile.close();

    for (int k = 0; k < 12; k++) 
    {

        if(foldType[k]=='x')
        {
            xFold = fold[k];
        
            for (int j = 0; j < yFold; j++) 
            {
                for (int i = 1; i <=xFold; i++) 
                {
                    diagramPtr[(xFold-i) * 1000 + j] += diagramPtr[(xFold+i) * 1000 + j];
                }
            }
        }
        else 
        {
            yFold = fold[k];
            
            for (int i = 0; i < xFold; i++)
            {
                for (int j = 1; j <= yFold; j++)
                {
                    diagramPtr[i * 1000 + (yFold-j)] += diagramPtr[i * 1000 + (yFold+j)];
                }
            }
            
        }

    }
    
    for (int j = 0; j < yFold; j++) {
        for (int i = 0; i < xFold; i++) {
            if (diagramPtr[i * 1000 + j] > 0) {
                cout<<'#';
            }
            else {
                cout << ' ';
            }
        }
        cout << endl;
    }
    
    //Count the dots
   /* for (int i = 0; i < xFold; i++) {
        for (int j = 0; j < yFold; j++) {
            if (diagramPtr[i * 1000 + j] > 0)
            {
              count++;
            }
        }
        
    }
    cout << count << endl;*/
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
    int value = 0, digitPower = 0;
    for (int i = endPlace; i >= beginPlace; i--)
    {
        value += ((static_cast<int>(intString[i])) - 48) * pow(10.0, static_cast<double>(digitPower));
        digitPower++;
    }
    return value;
}