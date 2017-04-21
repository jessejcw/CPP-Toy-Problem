//
// Created by jesse wang on 3/21/17.
//

#ifndef CODE1_WORDBREAKII_H
#define CODE1_WORDBREAKII_H

#include "inc_me.h"

class WordBreakII {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> mp;
        return wordBreakHelper(s, wordDict, mp);
    }
    vector<string> wordBreakHelper(string& s, vector<string>& dict, unordered_map<string, vector<string>>& memo) {
        if (memo.count(s)) {
            return memo[s];
        }
        const int sz = s.size();
        vector<string> res;
        if (sz <= 0) { return res; }
        for (int i = 1; i <= sz; i++) {
            string prefix = s.substr(0, i);
            if (std::find(dict.begin(), dict.end(), prefix) != dict.end()) {
                if (i == sz) {
                    res.push_back(prefix);
                } else {
                    string suffix = s.substr(i, sz-i);
                    vector<string> sub_res = wordBreakHelper(suffix, dict, memo);
                    for (string item : sub_res) {
                        item = prefix + " " + item;
                        res.push_back(item);
                    }
                }
            }
        }
        memo[s] = res;
        return res;
    }
};


#endif //CODE1_WORDBREAKII_H
