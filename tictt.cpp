#include <iostream>
#include <cstring>
#include <cctype>
/*
Ghazi Abbas
Period 4
C++ Fall sem
very basic tic tac toe

sources:
https://en.cppreference.com/w/cpp/language/functions
https://www.geeksforgeeks.org/difference-between-const-int-const-int-const-and-int-const/#
+ Galbraiths videos opn ampersand and pointers and arrays and function prototyping

*/

using namespace std;

const int boardSize = 3; //https://www.geeksforgeeks.org/difference-between-const-int-const-int-const-and-int-const/#

void resetBoard(char board[][boardSize]);
void printBoard(char board[][boardSize]);

int main()
{
    char board[boardSize][boardSize];
    resetBoard(board);
    printBoard(board);

    return 0;
}

void resetBoard(char board[][boardSize])
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[][boardSize])
{
    cout << "  a b c" << endl;

    for (int i = 0; i < boardSize; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < boardSize; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}





