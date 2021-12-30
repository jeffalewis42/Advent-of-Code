// adventOfCode14.cpp : 
//
/*What do you get if you take the quantity of the most common element and subtract the quantity of the least common element?*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;



int main()
{
    const int RULES = 100;
    string tempEntry, polymer, testPair, newBeginPair, newEndPair;
    map <string, char> insertionTable;
    map <string, unsigned long long int> pairCount;
    map <string, unsigned long long int> tempCount;
    unsigned long long int max = 0, min = 0;
    char letters[] = { 'C','S','F','N','P','H','O','V','B','K'};   
    unsigned long long int letterCount[] = { 0,0,0,0,0,0,0,0,0,0 };
    
    char insertionChar;
    
    ifstream inputFile;
    inputFile.open("input.txt");
    inputFile >> polymer;
   
    getline(inputFile, tempEntry);
    getline(inputFile, tempEntry);
   
    
    for (int i=0;i<RULES;i++) 
    {
        getline(inputFile, tempEntry);
        insertionTable.insert(pair<string,char>(tempEntry.substr(0, 2), tempEntry[6]));
        pairCount.insert(pair<string, unsigned long long int>(tempEntry.substr(0, 2), 0));
        tempCount.insert(pair<string, unsigned long long int>(tempEntry.substr(0, 2), 0));
        
    }
    
    inputFile.close();

    for (int i = 0; i < polymer.length(); i++) {
        for (int j = 0; j < 10; j++) {
            if (polymer[i] == letters[j]) {
                letterCount[j]++;
            }
        }
    }
   
    for (int i = 0; i < polymer.length() - 1; i++) {
        map<string, unsigned long long int>::iterator countItr;
        for (countItr = pairCount.begin(); countItr != pairCount.end(); ++countItr) {
            if (polymer.substr(i, 2) == countItr->first)
            {
                countItr->second++;
            }
        }
    }

    
    for (int j=0;j<40;j++){
    map<string, unsigned long long int>::iterator pairItr;
    
    for (pairItr = pairCount.begin(); pairItr != pairCount.end(); ++pairItr) {
        testPair = pairItr->first;
        insertionChar = insertionTable[testPair];
        for (int i = 0; i < 10; i++)
        {
            if (insertionChar == letters[i]) {
                letterCount[i] += pairItr->second;
            }
       }
        newBeginPair = testPair.substr(0, 1) + insertionChar;
        newEndPair = insertionChar+testPair.substr(1, 1);
        
        tempCount[newBeginPair] += pairItr->second;
        tempCount[newEndPair] += pairItr->second;
        pairCount[testPair] = 0;
    }
    
    pairCount.swap(tempCount);
    
    }
    
    max = letterCount[0];
    min = letterCount[0];
    for (int j = 1; j < 10; j++) {
        if (letterCount[j] > max) {
            max = letterCount[j];
        }
        if (letterCount[j] < min) {
            min = letterCount[j];
        }
    }
    cout << max - min << endl;
    
    return 0;
}
 
