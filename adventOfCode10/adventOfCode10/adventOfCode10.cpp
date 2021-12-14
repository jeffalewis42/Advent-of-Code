// adventOfCode10.cpp : 
//): 3 points.
//]: 57 points.
//}: 1197 points.
//> : 25137 points.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
unsigned long long int checkLine(string);
char openType(char key);
int points(char key);


int main()
{   vector <unsigned long long int> result;
    unsigned long long int total = 0;
    string entry[94];
    ifstream inputFile;


    inputFile.open("input.txt");
    for (int i = 0; i < 94; i++)
    {
        inputFile >> entry[i];
    }
    inputFile.close();
    for (int i = 0; i < 94; i++) {
        total=checkLine(entry[i]);
        
        if (total > 0) {
            result.push_back(total);
        }

    }
   
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++) {
        cout << i + 1 << " " << result[i] << endl;
    }

    /*cout << result[(result.size() + 1) / 2] << endl;*/
   
    
    return 0;
}

unsigned long long int checkLine(string entryString)
{  
    unsigned long long int total = 0;
    for (int i = 1; i < entryString.length(); i++) {
        if (entryString[i] == ')' || entryString[i] == ']' || entryString[i] == '}' || entryString[i] == '>') {
            if (entryString[i - 1] == openType(entryString[i])) {
                entryString.erase(i - 1, 2);
                i-=2;
            }
            else {
                return 0;
                /*return points(entryString[i]);Part 1*/
            }
        }

        
   }

   for (int i = entryString.length() - 1; i >= 0; i--)
   {
       total = total * 5 + points(entryString[i]);
       
   }
       
    return total;
}

char openType(char key) {
    switch (key)
    {
    case ')':
        return '(';
        break;
    case ']':
        return '[';
        break;
    case '}':
        return '{';
        break;
    case '>':
        return '<';
        break;
    }
}

int points(char key) {
    switch (key)
    {
    case ')':
        return 3;
        break;
    case ']':
        return 57;
        break;
    case '}':
        return 1197;
        break;
    case '>':
        return 25137;
        break;
    case '(':
        return 1;
        break;
    case '[':
        return 2;
        break;
    case '{':
        return 3;
        break;
    case '<':
        return 4;
        break;
    }
}

