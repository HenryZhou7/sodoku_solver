//
//  main.cpp
//  sodoku_solver
//
//  Created by Henry Zhou on 16/8/30.
//  Copyright © 2016年 Henry Zhou. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "grid.hpp"

using namespace std;

/* Functions that prompt the user for constructing a soduku
 * include error checking and defensive coding
 * all the input digit should fall into the range [0, 9]
 * 0 is for an empty block and all the others represent the number itself
 */
vector< vector<int> > createSodoku(){
    cout << "Please initialize your soduku according to the guide:" << endl;
    vector< vector<int> > user_input;
    vector< vector<int> > dummy;        //error input replacement
    
    for (int i = 0; i < 9; i++){
        vector<int> row_input;
        for (int j = 0; j < 9; j++){
            int temp;
            cin >> temp;
            if (temp > 9 || temp < 0)   //invalid input
                return dummy;
            row_input.push_back(temp);
        }
        user_input.push_back(row_input);
    }
    
    return user_input;
}


//Using the method of backtracking to solve the soduku problem
void using_backtracking(Sodoku problem){
    cout << "Using the Alg called: Backtracking" << endl;
    bool solved = problem.backtracking();
    if (solved)
        cout << "Problem Solved" << endl;
    else
        cout << "Invalid problem? Please make sure" << endl;
    problem.printGrid();
}


int main(int argc, const char * argv[]) {
    
    srand((unsigned)time(NULL));        //setting up the random seed
    Sodoku test(createSodoku());
    
    
    test.printGrid();
    test.rand_initialize();
    test.printGrid();
    
    if (test.win())
        cout << "The initialization step is done" << endl;
    
    test.sa_solve();
    
    cout << "The SA alg result" << endl;
    test.printGrid();
    
    
    return 0;
}

