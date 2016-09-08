#include "../include/sudoku_solver.hpp"

using namespace std;

int main(int argc, char** argv) {
    cout << "Sudoku Solver v1.1" << endl << endl;

    vector<int> sudoku_grid;
    unsigned int curr_location = 0;
    bool solved = false;
    bool forward = true;

    SudokuSolver solver;

    solver.initGrid(sudoku_grid);
    solver.printGrid(sudoku_grid);

    while(!solved) {
        if(curr_location == GRIDSIZE*GRIDSIZE) {
            solved = true;
        } else if(solver.emptyLocation(curr_location)) {
            ++sudoku_grid[curr_location];
            if(sudoku_grid[curr_location] > GRIDSIZE) {
                sudoku_grid[curr_location] = 0;
                forward = false;
                --curr_location;
            } else if(solver.isValid(curr_location, sudoku_grid)) {
                ++curr_location;
                forward = true;
            } else {
                forward = true;
            }
        } else {
            if(forward) {
                ++curr_location;
            } else {
                --curr_location;
            }
        }
    }

    cout << endl;
    solver.printGrid(sudoku_grid);
    
    return 0;
}
