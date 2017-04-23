//
// Created by jesse_wang on 3/19/2017.
//

#ifndef CODE1_MAXIMUMSIZESUBARRAYSUMEQUALSK_H
#define CODE1_MAXIMUMSIZESUBARRAYSUMEQUALSK_H

#include "inc_me.h"

class MaximumSizeSubarraySumEqualsK {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        const int sz = nums.size();
        if (sz == 0) { return 0; }
        int j =0;
        int sum = 0;
        int res = INT_MIN;
        for (int i= 0; i < sz; i++) {
            j=i;
            sum = 0;
            while (j < sz && sum != k) {
                sum += nums[j];
                j++;
                if (sum == k) {
                    break;
                }
            }
            if (sum == k && j-i > res) {
                res = j-i;
            }
            sum -= nums[i];
        }
        return res == INT_MIN ? 0 : res;

    }
};


#endif //CODE1_MAXIMUMSIZESUBARRAYSUMEQUALSK_H
