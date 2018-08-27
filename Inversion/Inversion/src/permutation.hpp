//
//  permutation.hpp
//  Inversion
//
//  Created by Mridul Sahu on 27/08/18.
//  Copyright © 2018 Open Source. All rights reserved.
//

#ifndef permutation_hpp
#define permutation_hpp

#include <vector>

std::vector<int> get_inversion_sequence(std::vector<int> &perm);
bool is_valid_inversion_sequence(std::vector<int> &seq);
std::vector<int> get_permutation_from_inversion(std::vector<int> &inv);
int count_permutations_with_inversion_disorder(int n, int k);

#endif /* permutation_hpp */
