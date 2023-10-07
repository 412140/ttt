#include <iostream>

using namespace std;
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
const int boardSize = 3; // convenience sake
const char emptyCell = ' ';//doing this instead of the old one where i was manually typing it in, also this way works better with the real board design i made
const char playerX = 'X';
const char playerO = 'O';
//https://www.geeksforgeeks.org/difference-between-const-int-const-int-const-and-int-const/

void initializeBoard(char board[boardSize][boardSize])//simple double for loop to target every part of the board and make it empty 
{//galbraiths video ^
    for (int i = 0; i < boardSize; ++i) 
    {
        for (int j = 0; j < boardSize; ++j) 
        {
            board[i][j] = emptyCell;
        }
    }
}

// kind of translated this from a computer hardware 2 assignment from last year which was actually in python, liked this board better than abc 123
void printBoard(const char board[boardSize][boardSize]) 
{
    for (int i = 0; i < boardSize; ++i) 
    {
        for (int j = 0; j < boardSize; ++j) 
        {
            cout << board[i][j];
            if (j < boardSize - 1)
                cout << "|";
        }
        cout << "\n";
        if (i < boardSize - 1)
            cout << "-----\n";
    }
}
//https://www.youtube.com/watch?v=j5B9GwJO8HA YouTube video i found on bool functions
bool isMoveLegal(const char board[boardSize][boardSize], int row, int col) 
{
    return (row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] == emptyCell);
}
//kind of similar to the java video one
bool checkWin(const char board[boardSize][boardSize], char currentPlayer) 
{
    for (int i = 0; i < boardSize; ++i) 
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) 
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) 
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) 
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) 
        return true;
    return false;
}

bool isBoardFull(const char board[boardSize][boardSize]) 
{
    for (int i = 0; i < boardSize; ++i) 
    {
        for (int j = 0; j < boardSize; ++j) 
        {
            if (board[i][j] == emptyCell)
                return false;
        }
    }
    return true;
}

int main() 
{
    char board[boardSize][boardSize];
    initializeBoard(board);
    char currentPlayer = playerX;

    int winsX = 0, winsO = 0, ties = 0;

    while (true) 
    {
        printBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row[0-" << boardSize - 1 << "] col[0-" << boardSize - 1 << "]): ";
        cin >> row >> col;
	// enter row enter col this was an attempt at conserving space.
        if (!isMoveLegal(board, row, col)) 
        {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) 
        {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            if (currentPlayer == playerX)
                winsX++;
            else
                winsO++;
            initializeBoard(board);
        } 
        else if (isBoardFull(board)) 
        {
            printBoard(board);
            cout << "It's a tie!\n";
            ties++;
            initializeBoard(board);
        }

        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
    }

}
