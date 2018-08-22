//
//  main.cpp
//  Generate
//
//  Created by Mridul Sahu on 22/08/18.
//  Copyright © 2018 Open Source. All rights reserved.
//

#include <iostream>
#include "permutation.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    auto permutations = generate_permutations(4);
    for (vector<int> &v : permutations) {
        cout << "{ ";
        for (int x : v) {
            cout << x << ", ";
        }
        cout << "}\n";
    }
    return 0;
}
