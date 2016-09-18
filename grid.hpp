//
//  grid.hpp
//  sodoku_solver
//
//  Created by Henry Zhou on 16/8/30.
//  Copyright © 2016年 Henry Zhou. All rights reserved.
//

#ifndef grid_hpp
#define grid_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * class that contains a 9 x 9 grid Sodoku problem
 * original_grid_ is the grid that the user has input, serving as a helper grid
 * solve_grid is the grid that the alg is working on
 * its methods include various algorithm to solve the problem
 *                     and different helper functions
 */
class Sodoku{
private:
    vector< vector<int> > original_grid_;
    vector< vector<int> > solve_grid_;
    
public:
    Sodoku(vector< vector<int> > user_grid);
    
    
    bool backtracking();
    vector< vector<int> > backtrackinghelper(vector<vector<int>> grid);
    
    bool win(vector< vector<int> >);
    bool valid_grid(vector< vector<int> >);
    bool valid_input(); //check whether the input from the user is valid
    void printGrid();
    
};

#endif /* grid_hpp */
