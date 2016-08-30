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
    grid_ = user_grid;
}

//Print the grid in a readable fashion
void Sodoku::printGrid(){
    
    cout << "Printing the grid" << endl;
    
    //print the upper boundary
    cout << "+-----------------------+" << endl;
    
    for (int i = 0; i < 9; i++){            //Print row
        
        cout << "| ";
        for (int j = 0; j < 9; j++){        //Print col
            
            if (grid_[i][j] != 0)
                cout << grid_[i][j] << " ";
            else
                cout << " ";
            
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
