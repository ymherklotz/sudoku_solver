#include "../include/sudoku_solver.hpp"

using namespace std;

SudokuSolver::SudokuSolver() {
    int tmp_int;
    grid_file.open("/home/yannherklotz/Github/sudoku_solver/resources/grid.txt", ios::in);
    
    if(grid_file.is_open()) {
        cout << "File successfully opened..." << endl << endl;
    } else {
        cout << "Failed to open file..." << endl << endl;
        exit(EXIT_FAILURE);
    }
    
    while(grid_file >> tmp_int) {
        grid.push_back(tmp_int);
    }
}

SudokuSolver::~SudokuSolver() {
    
}

void SudokuSolver::printGrid(vector<int> &grid) {
    int count = 0;
    int row = 0;
    int sep_count = 0;
    for(int box : grid) {
        cout << box << " ";
        ++count;

        if(count % SEPSIZE == 0 && count % GRIDSIZE != 0) {
            cout << "| ";
        }
        
        if(count >= GRIDSIZE) {
            count = 0;
            cout << endl;
            ++row;
        }

        if(row >= SEPSIZE && sep_count < SEPSIZE-1) {
            for(unsigned int i = 0; i < GRIDSIZE + SEPSIZE-1; ++i) {
                cout << "- ";
            }
            cout << endl;

            row = 0;
            ++sep_count;
        }
    }
}

void SudokuSolver::initGrid(std::vector<int> &new_grid) {
    new_grid = this->grid;
}

bool SudokuSolver::checkBox(unsigned int &grid_location, vector<int> &curr_grid) {
    int box_location = getBox(grid_location);

    for(unsigned int i = 0; i < curr_grid.size(); ++i) {
        if(getBox(i) == box_location && grid_location != i) {
            if(curr_grid[grid_location] == curr_grid[i]) {
                return false;
            }
        }
    }

    return true;
}

bool SudokuSolver::checkRow(unsigned int &grid_location, vector<int> &curr_grid) {
    int row = grid_location / GRIDSIZE;

    for(unsigned int i = 0; i < curr_grid.size(); ++i) {
        int tmp_row = i / GRIDSIZE;
        if(row == tmp_row && grid_location != i) {
            if(curr_grid[grid_location] == curr_grid[i]) {
                return false;
            }
        }
    }

    return true;
}

bool SudokuSolver::checkColumn(unsigned int &grid_location, vector<int> &curr_grid) {
    int column = grid_location % GRIDSIZE;

    for(unsigned int i = 0; i < curr_grid.size(); ++i) {
        int tmp_col = i % GRIDSIZE;
        if(column == tmp_col && grid_location != i) {
            if(curr_grid[grid_location] == curr_grid[i]) {
                return false;
            }
        }
    }

    return true;
}

bool SudokuSolver::emptyLocation(unsigned int &curr_location) {
    if(grid[curr_location] == 0) {
        return true;
    }

    return false;
}

bool SudokuSolver::isValid(unsigned int &grid_location, std::vector<int> &curr_grid) {
    if(checkColumn(grid_location, curr_grid) && checkRow(grid_location, curr_grid) && checkBox(grid_location, curr_grid)) {
        return true;
    }

    return false;
}

int SudokuSolver::getBox(unsigned int grid_location) {
    int column = grid_location % GRIDSIZE;

    int box_row = grid_location / (GRIDSIZE * SEPSIZE);
    int box_column = column / SEPSIZE;

    int box_location = box_row * 3 + box_column;
    return box_location;
}
