//
//  permutation.cpp
//  Inversion
//
//  Created by Mridul Sahu on 27/08/18.
//  Copyright © 2018 Open Source. All rights reserved.
//

#include "permutation.hpp"

bool is_valid_permutaion(std::vector<int> &perm) {
    int n = int(perm.size());
    
    std::vector<bool> seen(n, false);
    
    for(int i = 0; i < n; ++i) {
        if (seen[i])
            return false;
        seen[i] = true;
    }
    
    for(int i = 0; i < n; ++i) {
        if (!seen[i])
            return false;
    }
    
    return true;
}

std::vector<int> get_inversion_sequence(std::vector<int> &perm) {
    if (!is_valid_permutaion(perm))
        throw "invalid permutaion sequence";
    
    int n = int(perm.size());
    
    std::vector<int> inv(n);
    
    for(int i = 0; i < n; ++i) {
        int val = perm[i];
        int cnt = 0;
        
        for(int j = i-1; j >= 0; --j) {
            if (perm[j] > val)
                ++cnt;
        }
        
        inv[val - 1] = cnt;
    }
    
    return inv;
}

bool is_valid_inversion_sequence(std::vector<int> &seq) {
    
    int n = int(seq.size());
    
    for (int i = 0; i < n; ++i) {
        if (seq[i] < 0 || seq[i] >= n-i)
            return false;
    }
    
    return true;
}

std::vector<int> get_permutation_from_inversion(std::vector<int> &inv) {
    
    if (!is_valid_inversion_sequence(inv))
        throw "invalid inversion sequnce";
    
    int n = int(inv.size());
    
    std::vector<int> empty_positions(n);
    std::vector<int> perm(n);
    
    for (int i = 0; i < n; ++i) {
        empty_positions[i] = i;
    }
    
    for (int i = 0; i < n; ++i){
        perm[empty_positions[inv[i]]] = i+1;
        empty_positions.erase(empty_positions.begin() + inv[i]);
    }
    
    return perm;
}

int permutations_with_k_disorder(int n, int k, int **solutions) {
    
    if (n == 0)
        return 0;
    
    if (solutions[n][k] != 0)
        return solutions[n][k];
    
    if (k == 0)
        return solutions[n][k] = 1;
    
    int sum = 0;
    
    for (int i = 0; i < n && k - i >= 0; ++i) {
        sum += permutations_with_k_disorder(n-1, k-i, solutions);
    }
    
    return solutions[n][k] = sum;
}

int count_permutations_with_inversion_disorder(int n, int k) {
    if (n == 0)
        return 0;
    
    if (k == 0)
        return 1;
    
    int **arr = new int*[n+1];
    
    for (int i = 0; i <= n; ++i) {
        arr[i] = new int[k+1]();
    }
    
    //memset(arr, -1, sizeof(int) * (n+1) * (k+1));
    
    return permutations_with_k_disorder(n, k, arr);
}
