# sudoku-solver

A simple C++ solver for 9x9 Sudoku puzzles using recursive backtracking.

### How It Works
- Finds empty cells (represented by `0`).
- Validates numbers (1-9) against Sudoku rules (row, column, and 3x3 subgrid).
- Uses recursive backtracking to try numbers and backtrack when stuck.

### Run
```bash
g++ main.cpp -o sudoku
./sudoku
