/*

    -- -- -- - -- -- -- - -- -- --
  | 00 01 02 | 03 04 05 | 06 07 08 |
  | 09 10 11 | 12 13 14 | 15 16 17 |
  | 18 19 20 | 21 22 23 | 24 25 26 |
  | -- -- -- - -- -- -- - -- -- -- |
  | 27 28 29 | 30 31 32 | 33 34 35 |
  | 36 37 38 | 39 40 41 | 42 43 44 |
  | 45 46 47 | 48 49 50 | 51 52 53 |
  | -- -- -- - -- -- -- - -- -- -- |
  | 54 55 56 | 57 58 59 | 60 61 62 |
  | 63 64 65 | 66 67 68 | 69 70 71 |
  | 72 73 74 | 75 76 77 | 78 79 80 |
    -- -- -- - -- -- -- - -- -- --
  
 */

#ifndef SUDOKU_SOLVER_HEAD
#define SUDOKU_SOLVER_HEAD

#define GRIDSIZE 9
#define SEPSIZE 3

#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>

class SudokuSolver {
public:
    SudokuSolver();
    ~SudokuSolver();

    void printGrid();
    bool checkBox(unsigned int &grid_location, std::vector<int> &curr_grid);
    bool checkRow(unsigned int &grid_location, std::vector<int> &curr_grid);
    bool checkColumn(unsigned int &grid_location, std::vector<int> &curr_grid);
    int getBox(unsigned int grid_location);
protected:
private:
    std::vector<int> grid;
    std::ifstream grid_file;
};

#endif
