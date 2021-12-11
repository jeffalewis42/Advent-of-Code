// adventOfCode4a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
    string numbersCalled;
    vector <int> numberCalled;
    int startNum = 0, newCommaSpot = 0, tempNumber=0, unmarkedSum=0, winningBoards=0;  //winningBoards was added for second part
    int stringPlace = 0, place = 0, numValue = 0, winningBoard=0, lastNumber=0;
    int boardArray[100][5][5];
    bool boardMatchArray[100][5][5], boardWon[100];//winner=false;  used in first part.. boardWon[0] array was added for second part
    
    ifstream inputFile;
    inputFile.open("input.txt");
    inputFile >> numbersCalled;//this will get the numbers to be called out in Bingo

    for (int board = 0; board < 100; board++)//initializing status array
    {
        boardWon[board] = false;//added for second part
        for (int row = 0; row < 5; row++)
        {
            
            for (int col = 0; col < 5; col++)
            {
                boardMatchArray[board][row][col] = false;
            }
        }
    }

do {
        
        if (numbersCalled[stringPlace] == ',')
        {
            newCommaSpot = stringPlace;
            place = 0, tempNumber = 0;
            for (int j = newCommaSpot-1; j >=startNum; j--)
            {
                tempNumber += ((static_cast<int>(numbersCalled[j])) - 48) * pow(10.0, static_cast<double>(place));
                place++;
            }
            numberCalled.push_back(tempNumber);
            startNum = newCommaSpot + 1;
            
        }
               stringPlace++;
    } while (stringPlace<numbersCalled.length());//parse numbers that would be called out in Bingo

    for (int b = 0; b < 100; b++) //read boards from input file
    {
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                inputFile >> boardArray[b][r][c];
            }
        }
    }

    for (int i = 0; i < numberCalled.size() && winningBoards<100; i++)//checks each number called out against each of the boards
    {
        for (int boards = 0; boards < 100&&winningBoards<100; boards++)
        {
            if (!boardWon[boards]) {
                for (int row = 0; row < 5; row++)
                {
                    for (int col = 0; col < 5; col++)
                    {

                        if (boardArray[boards][row][col] == numberCalled[i])
                        {
                            boardMatchArray[boards][row][col] = true;
                        }
                    }
                }

                for (int row = 0; row < 5; row++)//check for winner by rows
                {
                    if (boardMatchArray[boards][row][0] &&
                        boardMatchArray[boards][row][1] &&
                        boardMatchArray[boards][row][2] &&
                        boardMatchArray[boards][row][3] &&
                        boardMatchArray[boards][row][4])
                    {

                        /*winner = true;*/
                        boardWon[boards] = true;//added for second part
                        winningBoards++;//added for second part
                        winningBoard = boards;
                    }
                }
                if (!boardWon[boards])
                {
                    for (int col = 0; col < 5; col++)//check for winner by columns
                    {
                        if (boardMatchArray[boards][0][col] &&
                            boardMatchArray[boards][1][col] &&
                            boardMatchArray[boards][2][col] &&
                            boardMatchArray[boards][3][col] &&
                            boardMatchArray[boards][4][col])
                        {
                            /*winner = true;*/
                            boardWon[boards] = true;//added for second part
                            winningBoards++;//added for second part
                            winningBoard = boards;
                        }
                    }
                }
            }
        }
        lastNumber = numberCalled[i];

    }
    
    for (int row = 0; row < 5; row++)//get sum of the unmarked spots on the winning bingo card
    {
        
        for (int col = 0; col < 5; col++)
        {
            
            if (boardMatchArray[winningBoard][row][col]==false)
            {
                unmarkedSum += boardArray[winningBoard][row][col];
            }
        }
    }
    
    cout << endl;
    cout << "Winning Board: " << winningBoard << endl;
    cout << "Last number: " << lastNumber << endl;
    cout << "Unmarked Sum: " << unmarkedSum << endl;
    cout << lastNumber * unmarkedSum << endl;
   
    inputFile.close();
    return 0;
}

