//
//  SA_implementation.cpp
//  sodoku_solver
//
//  Created by Henry Zhou on 9/18/16.
//  Copyright © 2016 Henry Zhou. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "grid.hpp"

using namespace std;

void Sodoku::test_hello(){
    cout << "This way works!" << endl;
}


//based on the current status of solve_grid_
//randomly assign all the blank slots with value that satisfy the basics
//that is making sure that the digits 1 to 9 appear exactly 9 times in the grid
void Sodoku::rand_initialize(){
    
    //first count how many digits are already there
    vector<int> curr_status(9, 0);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (solve_grid_[i][j] != 0)
                curr_status[solve_grid_[i][j] - 1]++;
    
    //randomly assign a number to the empty slot given the appearance limit
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (solve_grid_[i][j] == 0){
                int num;
                do{
                    num = rand() % 9;
                }while (curr_status[num] >= 9);
                solve_grid_[i][j] = num + 1;
                curr_status[num]++;
            }
    return;
}



//find the relative cost of the current solve_grid_
//finding the difference between the sum of each row/col/block and sum
//square the difference and take the square root
//accumulate and then take the mean average
double Sodoku::cost(){
    double sum = 0;
    
    //finding all the row sum
    for (int i = 0; i < 9; i++){
        double temp_sum = 0;
        for (int j = 0; j < 9; j++)
            temp_sum += solve_grid_[i][j];
        sum += (temp_sum - 45) * (temp_sum - 45);
    }
    cout << sum << endl;
    //finding all the col sum
    for (int j = 0; j < 9; j++){
        double temp_sum = 0;
        for (int i = 0; i < 9; i++)
            temp_sum += solve_grid_[i][j];
        sum += (temp_sum - 45) * (temp_sum - 45);
    }
    cout << sum << endl;
    //finding all the block sum
    for (int p = 0; p < 3; p++){
        for (int q = 0; q < 3; q++){
            int temp_sum = 0;
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    temp_sum += solve_grid_[i + 3 * p][j + 3 * q];
                }
            }
            sum += (temp_sum - 45) * (temp_sum - 45);
        }
    }
    
    return sqrt((double)sum) / 27;
}