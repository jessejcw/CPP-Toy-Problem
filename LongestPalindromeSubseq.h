//
// Created by jesse_wang on 3/18/2017.
//

#ifndef CODING1_LONGESTPALINDROMESUBSEQ_H
#define CODING1_LONGESTPALINDROMESUBSEQ_H

#include "inc_me.h"
// LC 516 https://discuss.leetcode.com/topic/78603/straight-forward-java-dp-solution
class LongestPalindromeSubseq {
public:
    int longestPalindromeSubseq(string s) {
        const int sz = s.size();
        if (sz == 0) { return 0; }
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        for (int i = sz-1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j <sz; j++) {
                if (s[i] ==s[j]) {
                    dp[i][j] = dp[i+1][j-1]+2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][sz-1];
    }

};


#endif //CODING1_LONGESTPALINDROMESUBSEQ_H
