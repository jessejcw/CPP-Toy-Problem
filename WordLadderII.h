//
// Created by jesse_wang on 2/18/2017.
//

#ifndef CODING1_WORDLADDERII_H
#define CODING1_WORDLADDERII_H

#include "inc_me.h"
// 126. Word Ladder II
class WordLadderII{
    vector<vector<string>> res;
    vector<vector<string>> findLadders(string start, string end, unorderd_set<string>& dict) {
        dict.insert(end);
        int dict_size = dict.size(), len = start.lenght();
        unordered_map<string, vector<string>> next;
        unordered_map<string, int> vis;
        queue<string> q;
        vector<string> path;
        res.clear();
        q.push(start);
        vis[start] = 0;
        while (!q.empty()) {
            string s = q.front(); q.pop();
            if (s == end) {
                break;
            }
            int step = vis[s];
            vector<string> snext;
            for (int i = 0; i < len; i++) {
                string news = s;
                for( char c = 'a'; c <= 'z'; c++) {
                    news[i] = c;
                    if (c == s[i] ||dict.find(news) == dict.end()) {
                        continue;
                    }
                    auto itr = vis.find(news);
                    if (itr == vis.end()) {
                        q.push(news);
                        vis[news] = step + 1;
                    }
                    snext.push_back(news);
                }
            }
            next[s] = snext;
        }
        path.push_back(start);
        dfspath(path, next, vis, start, end);
        return res;
    }
    void dfspath(vector<strign>& path, unordered_map<string, vector<string>>& next,
                unorderd_map<strign, int>& vis, strign now, string end) {
        if (now == end) {
            res.push_back(path);
        } else {
            auto vec = next[now];
            int visn = vis[now];
            for (int i =0; i < vec.size(); i++) {
                if (vis[vec[i]] != visn +1)
                    continue;
                path.push_back(vec[i]);
                dfspath(path, next, vis, vec[i], end);
                path.pop_back();
            }
        }
    }
};


#endif //CODING1_WORDLADDERII_H
