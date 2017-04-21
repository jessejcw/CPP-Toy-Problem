//
// Created by jesse wang on 3/10/17.
//

#ifndef CODE1_WORDLADDER1_H
#define CODE1_WORDLADDER1_H

#include "inc_me.h"

class WordLadder1 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) {
            return 0;
        }
        unordered_set<string> visited;
        queue<pair<string, int>> word_queue;
        word_queue.push(make_pair(beginWord, 1));
        while (!word_queue.empty()) {
            pair<string, int> curr = (pair<string, int> &&) word_queue.front(); word_queue.pop();
            string word = curr.first;
            for (auto& c : word) {
                char c0 = c;
                for (c = 'a'; c <= 'z'; c++) {
                    if (c == c0) { continue; }
                    if (word == endWord) {
                        return curr.second+1;
                    }
                    auto itr = find(wordList.begin(), wordList.end(), word);
                    if (itr != wordList.end() && visited.count(word) ==0) {
                        visited.insert(word);
                        word_queue.push(make_pair(word, curr.second+1));
                    }

                }
                c = c0;
            }
        }
        return 0;
    }

};


#endif //CODE1_WORDLADDER1_H
