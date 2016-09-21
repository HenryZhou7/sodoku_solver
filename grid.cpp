//
//  grid.cpp
//  sodoku_solver
//
//  Created by Henry Zhou on 16/8/30.
//  Copyright © 2016年 Henry Zhou. All rights reserved.
//

#include "grid.hpp"

//Constructor for the class, the user gives a string
//assume user_grid is a valid input
Sodoku::Sodoku(vector< vector<int> > user_grid){
    original_grid_ = user_grid;
    solve_grid_ = user_grid;
}


//using back-tracking to solve the soduku problem
//essentially updating the solve_grid_ data member
bool Sodoku::backtracking(){
    
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            
            if (solve_grid_[i][j] == 0){
                for (int content = 1; content <= 9; content++){
                    solve_grid_[i][j] = content;
                    if (valid_grid(solve_grid_)){
                        if (backtracking()){
                            return true;
                        }
                    }
                }
                solve_grid_[i][j] = 0;
                return false;
            }
        }
    }

    return true;
    
}


//a weaker condition where you win the game
//see if each digit from 1 to 9 appears exactly nine times
bool Sodoku::win(){
    vector<int> accum(9, 0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (solve_grid_[i][j] != 0)
                accum[solve_grid_[i][j] - 1]++;
        }
    }
    for (int i = 0; i < 9; i++)
        if (accum[i] != 9)
            return false;
    
    return true;
}

//checking if the grid is currently valid
//if there is one term that doesn't satisfy the winning condition
//the definition of a valid soduku is that
//1. each row contains number from 1 to 9
//2. each col contains number from 1 to 9
//3. each n x n building block contains number from 1 to 9
bool Sodoku::valid_grid(vector< vector<int> > grid){
    
    //use this standard vector to find validness
    vector<int> standard(9, 1);
    
    //checking rows' sum
    for (int i = 0; i < 9; i++){
        
        vector<int> temp(9, 1);
        standard = temp;
        
        for (int j = 0; j < 9; j++)
            if (grid[i][j] == 0)
                continue;
            else
                standard[grid[i][j] - 1]--;
        
        for (int itr = 0; itr < 9; itr++)
            if (standard[itr] < 0)
                return false;
    }
    
    //checking cols' sum
    for (int j = 0; j < 9; j++){
        
        vector<int> temp(9, 1);
        standard = temp;
        
        for (int i = 0; i < 9; i++)
            if (grid[i][j] == 0)
                continue;
            else
                standard[grid[i][j] - 1]--;
        
        for (int itr = 0; itr < 9; itr++)
            if (standard[itr] < 0)
                return false;
    }
    
    //checking small grids' sum
    for (int p = 0; p < 3; p++){        //p and q are deviation degree
        for (int q = 0; q < 3; q++){
            
            vector<int> temp(9, 1);
            standard = temp;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (grid[i + 3 * p][j + 3 * q] == 0)
                        continue;
                    else
                        standard[grid[i + 3 * p][j + 3 * q] - 1]--;
            
            for (int itr = 0; itr < 9; itr++)
                if (standard[itr] < 0)
                    return false;
        }
    }
    
    return true;
}

//check to see whether the input from the user a valid input
bool Sodoku::valid_input(){
    if (original_grid_.size() != 9)
        return false;
    else
        return true;
}

//Print the grid in a readable fashion
//print the grid that is being solved
void Sodoku::printGrid(){
    
    cout << "Printing the grid" << endl;
    
    //print the upper boundary
    cout << "+-----------------------+" << endl;
    
    for (int i = 0; i < 9; i++){            //Print row
        
        cout << "| ";
        for (int j = 0; j < 9; j++){        //Print col
            
            if (solve_grid_[i][j] != 0)
                cout << solve_grid_[i][j] << " ";
            else                            //The case where the block is empty
                cout << "  ";
            
            if (j == 2 || j == 5)           //Separate col block
                cout << "| ";
        }
        cout << "| " << endl;
        
        if (i == 2 || i == 5)               //Separate row block
            cout << "|-------+-------+-------|" << endl;
        
    }
    
    //print the lower boundary
    cout << "+-----------------------+" << endl;

}
