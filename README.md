# Sudoku Solver

A clean and efficient C++ console application that solves standard 9x9 Sudoku puzzles using a recursive backtracking algorithm.

## Features
* **Recursive Backtracking:** Utilizes an optimized backtracking approach to find solutions dynamically.
* **Validation Engine:** Instantly checks constraints across rows, columns, and 3x3 subgrids to ensure moves are valid.
* **Clear Output:** Displays the initial unsolved board and the completed solution.

## How It Works
The solver uses a classic algorithmic strategy:
1. Searches the grid for an empty cell.
2. Tentatively places a digit from 1 to 9 that satisfies Sudoku rules.
3. Recursively moves to the next empty cell.
4. If a dead-end is reached, it backtracks, erases the choice, and tries the next number.

## Requirements
To run this project locally, you just need a standard C++ compiler (like GCC/g++).
