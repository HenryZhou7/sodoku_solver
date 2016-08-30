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
 * its data member has a 2D vector containging the grid information
 * its methods include various algorithm to solve the problem
 *                     and different helper functions
 */
class Sodoku{
private:
    vector< vector<int> > grid_;
    
public:
    Sodoku(vector< vector<int> > user_grid);
    
    void printGrid();
    
};

#endif /* grid_hpp */
