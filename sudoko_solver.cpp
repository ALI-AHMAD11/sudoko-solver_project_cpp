// task number 3
#include <iostream>
using namespace std;
// defining the size constant

#define N 9

// Function to printt the Sudoku board

void printBoard(int board[N][N])
{  // for outer bondry 
    cout << "\n+-------+-------+-------+\n";

    for (int row = 0; row < N; row++)
    {
        cout << "| ";

        for (int col = 0; col < N; col++)
        {
            if (board[row][col] == 0)
                cout << ". ";
            else
                cout << board[row][col] << " ";

            // Draw vertical separators after every 3 columns
            if ((col + 1) % 3 == 0)
                cout << "| ";
        }

        cout << endl;

        // Draw horizontal separators after every 3 rows
        if ((row + 1) % 3 == 0)
            cout << "+-------+-------+-------+\n";
    }
}

// Check if a number can be placed safely
bool isSafe(int board[N][N], int row, int col, int num)
{
    // Check row
    for (int x = 0; x < N; x++)
    {
        if (board[row][x] == num)
            return false;
    }

    // Check column
    for (int x = 0; x < N; x++)
    {
        if (board[x][col] == num)
            return false;
    }

    // Check 3×3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// Solve Sudoku using Backtracking
bool solveSudoku(int board[N][N])
{
    int row, col;
    bool emptyCell = false;

    // Find an empty cell
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (board[row][col] == 0)
            {
                emptyCell = true;
                break;
            }
        }

        if (emptyCell)
            break;
    }

    // No empty cells means puzzle solved
    if (!emptyCell)
        return true;

    // Try numbers from 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(board, row, col, num))
        {
            // Place number
            board[row][col] = num;

            // Recursive call
            if (solveSudoku(board))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    cout<<" ****_______WELCOME TO MY SUDOKO GAME______*****"<<endl;
    int board[N][N] =
    {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    cout << "Initial Sudoku Puzzle:\n";
    printBoard(board);

    if (solveSudoku(board))
    {
        cout << "\nSolved Sudoku:\n";
        printBoard(board);
    }
    else
    {
        cout << "\nNo solution exists." << endl;
    }

    return 0;
}