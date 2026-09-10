#include <iostream>
using namespace std;

const int N = 9;

// print the sudoku grid
void printGrid(int grid[N][N])
{
    for (int r = 0; r < N; r++)
    {
        if (r % 3 == 0 && r != 0)
        {
            cout << "------+-------+------\n";
        }
        for (int c = 0; c < N; c++)
        {
            if (c % 3 == 0 && c != 0)
            {
                cout << "| ";
            }
            if (grid[r][c] == 0)
                cout << ". ";
            else
                cout << grid[r][c] << " ";
        }
        cout << "\n";
    }
}

// check if placing num at grid[row][col] is valid
bool isValid(int grid[N][N], int row, int col, int num)
{
    // check row and column
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == num)
            return false;
        if (grid[i][col] == num)
            return false;
    }

    // check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (grid[startRow + r][startCol + c] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// solve the puzzle using backtracking
bool solveSudoku(int grid[N][N])
{
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    // find the first empty cell (marked with 0)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
            break;
    }

    // if no empty cell is left, puzzle is solved
    if (!isEmpty)
        return true;

    // try numbers from 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        if (isValid(grid, row, col, num))
        {
            grid[row][col] = num;

            // recurse to solve remaining cells
            if (solveSudoku(grid))
            {
                return true;
            }

            // backtrack if it leads to a dead end
            grid[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    // 0 represents empty cells
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    cout << "Original Sudoku Puzzle:\n";
    printGrid(grid);

    cout << "\nSolving...\n\n";

    if (solveSudoku(grid))
    {
        cout << "Solved Sudoku:\n";
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists for this puzzle!\n";
    }

    return 0;
}