//
// Created by jesse wang on 3/13/17.
//

#ifndef CODE1_REMOVEINVALIDPARENTHESIS_H
#define CODE1_REMOVEINVALIDPARENTHESIS_H

#include "inc_me.h"

class RemoveInvalidParenthesis {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0, pair = 0;
        unordered_set<string> res;
        string item;
        for (auto c : s) {
            if (c == '(') {
                left++;
            }
            else if (c == ')') {
                if (left) {
                    left--;
                } else {
                    right++;
                }
            }
        }
        traverse(s, 0, item, res, left, right, pair);
        return vector<string>(res.begin(), res.end());
    }

    void traverse(string& s, int pos, string item, unordered_set<string>& res, int left, int right, int pair) {
        if (s[pos] == '\0') {
            if (!pair) {
                res.insert(item);
            }
            return;
        }
        if (s[pos] == '(') {
            if (left) {
                traverse(s, pos+1, item, res, left-1, right, pair);
            }
            traverse(s, pos+1, item+"(", res, left, right, pair+1);
        } else if (s[pos] == ')') {
            if (right) {
                traverse(s, pos+1, item, res, left, right+1, pair);
            }
            if (pair) {
                traverse(s, pos+1, item+")", res, left, right, pair-1);
            }
        }
        else {
            traverse(s, pos+1, item+s[pos], res, left, right, pair);
        }
    }
};


#endif //CODE1_REMOVEINVALIDPARENTHESIS_H
