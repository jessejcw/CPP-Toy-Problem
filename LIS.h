//
// Created by jesse_wang on 3/18/2017.
//

#ifndef CODE1_LIS_H
#define CODE1_LIS_H

#include "inc_me.h"

class LIS {
public:
    int longestIncreasingSubseq(vector<int>& nums) {
        const int sz = nums.size();
        if (sz == 0) {
            return 0;
        }

        vector<int> dp(sz, 0);
        int longest =0;
        for (int i =0; i < sz; i++) {
            dp[i] = 1;
            for (int j =0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = dp[i] > dp[j]+1 ? dp[i] : dp[j]+1;
                }
            }
            if (dp[i] > longest) {
                longest = dp[i];
            }
        }
        return longest;
    }

    int longestIS(vector<int>& nums) {
        const int sz = nums.size();
        if (sz == 0) { return 0; }
        vector<int> min_last(sz+1, INT_MAX);

        for (int i = 0; i < sz; i++) {
            int index = binarySearch(min_last, nums[i]);
            min_last[index] = nums[i];
        }

        for (int i = sz; i>= 1; i--) {
            if (min_last[i] != INT_MAX) {
                return i;
            }
        }
        return 0;
    }

    int binarySearch(vector<int>& nums, int n) {
        int start = 0, end = nums.size()-1;
        while (start + 1 < end) {
            int mid = start + (end - start)/2;
            if (nums[mid] < n) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (nums[start]> n) {
            return start;
        }
        return end;
    }
};


#endif //CODE1_LIS_H
