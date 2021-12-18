// adventOfCode11.cpp : 
//
/*First, the energy level of each octopus increases by 1.
Then, any octopus with an energy level greater than 9 flashes. This increases the energy level of all adjacent octopuses by 1, 
including octopuses that are diagonally adjacent. 
If this causes an octopus to have an energy level greater than 9, it also flashes. 
This process continues as long as new octopuses keep having their energy level increased beyond 9. 
(An octopus can only flash at most once per step.)
Finally, any octopus that flashed during this step has its energy level set to 0, as it used all of its energy to flash.*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void step2(int [], bool [],int, int, bool);
void printGrid(int []);
void printGrid(bool []);
int step3(int [], bool []);



int main()
{
    string entry[10];
    int squid[100];
    bool squidFlashed[100], allFlashed=false;
    int flashTotal = 0, flashTemp=0;
int turn = 1;

    ifstream inputFile;
    inputFile.open("input.txt");
    for (int i = 0; i < 10; i++) {
        inputFile >> entry[i];
    }
    inputFile.close();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            squid[i * 10 + j] = entry[i][j]-48;
        }
    }
    
    

    //set the flashes grid to all false.
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            squidFlashed[i * 10 + j]=false;
        }
    }


      while(!allFlashed){  //change !allFlashed to turn<=100 for first part


    //First, the energy level of each octopus increases by 1.
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            squid[i * 10 + j] ++;
        }
    }


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            step2(squid, squidFlashed, i, j, true);
        }
    }

    flashTemp=step3(squid, squidFlashed);
    if (flashTemp == 100 && !allFlashed) {
        allFlashed = true;
        cout << turn << endl;
    }
    
    flashTotal += flashTemp;
    turn++;
    
}
    cout << flashTotal;

    return 0;
}

void step2(int squid[], bool test[], int x, int y, bool start)
{
    if (!start&&!test[x*10+y]) {
        squid[x * 10 + y]++;
    }
    
    if (squid[x * 10 + y] > 9 && !test[x * 10 + y])
    {
        test[x * 10 + y] = true;
        
        if (x > 0) {
step2(squid, test, x-1, y, false);

if (y > 0) {
step2(squid, test, x-1, y-1, false);
}
if (y < 9) {
step2(squid, test, x-1, y+1, false);
}
        }
        if (y > 0) {
step2(squid, test, x, y-1, false);
}
        
        if (y < 9) {
 step2(squid, test, x, y+1, false);
}
        if (x < 9) {
 step2(squid, test, x+1, y, false);
 if (y > 0) {
step2(squid, test, x+1, y-1, false);
 }
 if (y < 9) {
step2(squid, test, x+1, y+1, false);
 }
        }
        
    }
}

int step3(int squid[], bool test[]) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (squid[i * 10 + j] > 9) {
                squid[i * 10 + j] = 0;
                test[i * 10 + j] = false;
                count++;
            }
        }
    }
    return count;
}

void printGrid(int grid[])
{
    for (int i = 0; i < 10; i++) {
        cout << endl;

        for (int j = 0; j < 10; j++) {
            cout << grid[i * 10 + j];
        }
    }
    
    cout << endl;
}

void printGrid(bool grid[])
{
    for (int i = 0; i < 10; i++) {
        cout << endl;
        for (int j = 0; j < 10; j++) {
            cout << grid[i * 10 + j];
        }
    }
    cout << endl;
}
