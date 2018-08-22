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
    auto permutations = generate_permutations(9);
    
    cout << "Got " << permutations.size() << " Permutaions\n";
    
    for (vector<int> &v : permutations) {
        cout << "{ ";
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i];
            if (i != v.size() - 1)
                cout << ", ";
        }
        cout << " }\n";
    }
    return 0;
}
