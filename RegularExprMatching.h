//
// Created by jesse wang on 3/14/17.
//

#ifndef CODE1_REGULAREXPRMATCHING_H
#define CODE1_REGULAREXPRMATCHING_H

#include "inc_me.h"

class RegularExprMatching {
public:
    bool isMatch(string s, string p) {
        const int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        for (int i =0; i <=m; i++) {
            for (int j = 1; j <= n; j++) {
                // not '.' nor '*'
                if (p[j-1] != '.' && p[j-1] != '*') {
                    if (i > 0 && s[i-1]==p[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                } else if (p[j-1] == '.') {
                    if (i > 0) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                } else if (j > 1) {
                    if (dp[i][j-1] || dp[i][j-2]) {
                        dp[i][j] = true;
                    }
                    else if (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.'))
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};


#endif //CODE1_REGULAREXPRMATCHING_H
