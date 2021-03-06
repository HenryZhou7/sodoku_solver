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

#define SWAP_THRESHOLD 0.90

using namespace std;

//test for functions writing in a separate file
void Sodoku::test_hello(){
    cout << "This way works!" << endl;
}


//using simulated annealing to solve the input sodoku problem
void Sodoku::sa_solve(){
    
    //first randomly initialize the grid
    this->rand_initialize();
    
    double prev_cost = this->cost();
    while (this->cost() != 0){
        
        //randomly choose two slots and swap them
        vector<int> swap_coord = this->random_swap();
        this->swap_two_slots(swap_coord);
        
        //if the swaping is making the overall grid better, then keep it
        if (this->cost() < prev_cost){
            prev_cost = this->cost();
            continue;
        }
        else{   //otherwise, have a certain chance to switch back to the previous
            double rand_val = rand() % 100 / 100.0;
            if (rand_val >= SWAP_THRESHOLD){     //switching back to the original state
                this->swap_two_slots(swap_coord);
                continue;
            }
            else{   //keep the current state
                prev_cost = this->cost();
                continue;
            }
        }
        
    }
    
}


//swap two elements in the whole grid
//take in a vector indicating corresponding coordinates (x1, y1) and (x2, y2)
void Sodoku::swap_two_slots(vector<int> coord){
    int x1 = coord[0];
    int y1 = coord[1];
    int x2 = coord[2];
    int y2 = coord[3];
    
    int temp = solve_grid_[x1][y1];
    solve_grid_[x1][y1] = solve_grid_[x2][y2];
    solve_grid_[x2][y2] = temp;
}


//randomly choose newly filled two slots for swapping
//the returned vector consists of element x1 y1 x2 y2
vector<int> Sodoku::random_swap(){
    vector<int> result(4, 0);
    
    //choose x1, y1
    int x1;
    int y1;
    do{
        x1 = rand() % 9;
        y1 = rand() % 9;
    }while (original_grid_[x1][y1] != 0);
    result[0] = x1;
    result[1] = y1;
    
    //choose x2, y2
    int x2;
    int y2;
    do{
        x2 = rand() % 9;
        y2 = rand() % 9;
    }while (original_grid_[x2][y2] != 0);
    result[2] = x2;
    result[3] = y2;
    
    return result;
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
    
    //finding all the col sum
    for (int j = 0; j < 9; j++){
        double temp_sum = 0;
        for (int i = 0; i < 9; i++)
            temp_sum += solve_grid_[i][j];
        sum += (temp_sum - 45) * (temp_sum - 45);
    }
    
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