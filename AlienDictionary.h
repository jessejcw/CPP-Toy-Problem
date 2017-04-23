//
// Created by jesse_wang on 3/5/2017.
//

#ifndef CODING1_ALIENDICTIONARY_H
#define CODING1_ALIENDICTIONARY_H

#include "inc_me.h"
class AlienDictionary {
public:
    string alienOrder(vector<string>& words) {
        string res = "";
        if (words.size() == 0) { return res;}
        unordered_map<char, unordered_set<char>> mp;
        unordered_map<char, int> degree;
        for (string s : words) {
            for (char c : s) {
                degree[c] = 0;
            }
        }
        for (int i = 0; i < words.size()-1; i++) {
            string curr = words[i];
            string next = words[i+1];
            int length = min(curr.size(), next.size());
            for (int j=0; j < length; j++) {
                char c1 = curr[j];
                char c2 = next[j];
                if (c1 != c2) {
                    unordered_set<char> st = mp[c1];
                    if (!st.count(c2)) {
                        st.insert(c2);
                        mp[c1] = st;
                        degree[c2] = degree[c2]+1;
                    }
                    break;
                }
            }
        }
        queue<char> que;
        for (auto itr : degree) {
            if (itr.second == 0) {
                que.push(itr.first);
            }
        }
        while (!que.empty()) {
            char c1 = que.front();
            que.pop();
            res += c1;
            if (mp.count(c1)) {
                for (char c2 : mp[c1]) {
                    degree[c2] = degree[c2]-1;
                    if (degree[c2] == 0) {
                        que.push(c2);
                    }
                }
            }
        }
        if (res.size() != degree.size()) {
            return "";

        }
        return res;
    }
};


#endif //CODING1_ALIENDICTIONARY_H
