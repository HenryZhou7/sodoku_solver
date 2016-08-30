//
//  main.cpp
//  sodoku_solver
//
//  Created by Henry Zhou on 16/8/30.
//  Copyright © 2016年 Henry Zhou. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "grid.hpp"

using namespace std;

/* Functions that prompt the user for constructing a soduku
 * include error checking and defensive coding
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
            if (temp > 9 || temp < 1)   //invalid input
                return dummy;
            row_input.push_back(temp);
        }
        user_input.push_back(row_input);
    }
        
    
    return user_input;
}


int main(int argc, const char * argv[]) {
    
    Sodoku test(createSodoku());
    
    test.printGrid();
    
    
    return 0;
}

