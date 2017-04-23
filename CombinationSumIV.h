//
// Created by jesse_wang on 3/4/2017.
//

#ifndef CODING1_COMBINATIONSUMIV_H
#define CODING1_COMBINATIONSUMIV_H

#include "inc_me.h"
class CombinationSumIV {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0;j < n; j++) {
                if (i-nums[j] >= 0) {
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};


#endif //CODING1_COMBINATIONSUMIV_H
