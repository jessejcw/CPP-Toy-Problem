//
// Created by jesse_wang on 3/5/2017.
//

#ifndef CODING1_CONTIGUOUSARRAY_H
#define CODING1_CONTIGUOUSARRAY_H

#include "inc_me.h"
//https://discuss.leetcode.com/topic/79980/c-o-n-array-instead-of-unordered_map

class ContiguousArray {
    int findMaxLength(vector<int>& nums) {
        if (nums.size()==0) { return 0;}
        int max_len = 0, cur_sum=0;
        unordered_map<int, int> prefix;
        for (int i =0; i < nums.size(); i++) {
            cur_sum += nums[i] == 0 ? -1 : 1;
            if (cur_sum == 0) {
                max_len = max(max_len, i+1);
            }
            if (prefix.count(cur_sum) == 0) {
                prefix[cur_sum] = i;
            } else {
                max_len = max(cur_sum, i-prefix[cur_sum]);
            }
        }
        return max_len;
    }
};


#endif //CODING1_CONTIGUOUSARRAY_H
