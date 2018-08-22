//
//  permutation.cpp
//  Generate
//
//  Created by Mridul Sahu on 22/08/18.
//  Copyright © 2018 Open Source. All rights reserved.
//

#include "permutation.hpp"


int find_largest_mobile_number (std::vector<int> &values, std::vector<int> &directions, std::vector<int> &positions){
    for (int i = int(positions.size()) - 1; i >= 0; ++i) {
        int current_pos = positions[i];
        int next_pos = current_pos + directions[i];
        
        if (next_pos >= positions.size() || next_pos < 0)
            continue; // Not mobile
        
        else if (values[current_pos] > values[next_pos])
            return current_pos; // Is mobile
    }
    return -1;
}

void swap (int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void update_directions(int moved_value, std::vector<int> &directions) {
    for (int i = moved_value; i < directions.size(); ++i) {
        if (directions[i] == 1) {
            directions[i] = -1;
        } else {
            directions[i] = 1;
        }
    }
}

std::vector<std::vector<int>> generate_permutations (int n) {
    if (n <= 0) {
        throw "lenght of the sequence cannot be less than or equal to 0";
    }
    
    std::vector<std::vector<int>> permutations;
    std::vector<int> values(n), positions(n), directions(n);
    
    for(int i = 1; i <= n; ++i) {
        values[i-1] = i;
        // -1 means left & 1 means right
        directions[i-1] = -1;
        // a number 'n' is at postion 'postions[n-1]'
        positions[i-1] = i-1;
    }
    int mobile_pos = find_largest_mobile_number(values, directions, positions);
    int next_pos = 0;
    permutations.push_back(values);
    
    while (mobile_pos != -1) {
        next_pos = mobile_pos + directions[values[mobile_pos] - 1];
        update_directions(values[mobile_pos], directions);
        swap(values[mobile_pos], values[next_pos]);
        positions[values[mobile_pos] - 1] = next_pos;
        positions[values[next_pos] - 1] = mobile_pos;
        permutations.push_back(values);
        mobile_pos = find_largest_mobile_number(values, directions, positions);
    }
    
    return permutations;
}
