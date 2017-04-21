//
// Created by jesse_wang on 3/23/2017.
//

#ifndef CODE1_COMBINATIONSUM4_H
#define CODE1_COMBINATIONSUM4_H

#include "inc_me.h"

class CombinationSum4 {
public:
    int combo4(vector<int>& nums, int target) {
        const int sz = nums.size();
        if (sz == 0) { return 0; }
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i =1; i <= target; i++) {
            for (int n : nums) {
                if (i - n >= 0) {
                    dp[i] += dp[i-n];
                }
            }
        }
        return dp[target];
    }

};


#endif //CODE1_COMBINATIONSUM4_H
