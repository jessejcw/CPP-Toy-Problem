//
// Created by jesse wang on 3/21/17.
//

#ifndef CODE1_WORDBREAKI_H
#define CODE1_WORDBREAKI_H

#include "inc_me.h"

class WordBreakI {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int sz = s.size();
        if (sz == 0) { return false; }
        vector<bool> dp(sz+1, false);
        dp[0] = true;
        for (int i = 1; i <=sz; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] == false) {
                    continue;
                }
                string tmp = s.substr(j, i-j);
                if (std::find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[sz];
    }
};


#endif //CODE1_WORDBREAKI_H
