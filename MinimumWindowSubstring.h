//
// Created by jesse wang on 3/21/17.
//

#ifndef CODE1_MINIMUMWINDOWSUBSTRING_H
#define CODE1_MINIMUMWINDOWSUBSTRING_H

#include "inc_me.h"


class MinimumWindowSubstring {
public:
    string minWindow(string s, string t) {
        const int sz = s.size();
        unordered_map<char, int> mp; // t's char -> count
        string result;
        int j =0, mini_ = INT_MAX;
        for (const char& c : t) {
            mp[c]++;
        }
        int count = mp.size(); //
        for (int i =0; i < sz; i ++) {
            while (count != 0 && j < sz) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    count--;
                }
                j++;
                if (count ==0) {
                    break;
                }
            }
            if (count == 0 && j-i < mini_) {
                mini_ = j-i;
                result = s.substr(i, j-i);
            }
            if (mp[s[i]] == 0) {
                count++;
            }
            mp[s[i]]++;
        }
        return result;
    }

};


#endif //CODE1_MINIMUMWINDOWSUBSTRING_H
