//
// Created by jesse wang on 3/14/17.
//

#ifndef CODE1_LETTERCOMBINATIONOFAPHONENUMBER_H
#define CODE1_LETTERCOMBINATIONOFAPHONENUMBER_H

#include "inc_me.h"

class LetterCombinationOfaPhoneNumber {

public:
    const vector<string> keyboard = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) { return res; }
        dfs(digits, 0, "", res);
        return res;
    }
    void dfs(const string& digits, int curr, string path, vector<string>& res) {
        if (curr == digits.size()) {
            res.push_back(path);
            return;
        }
        for (auto c : keyboard[digits[curr] - '0']) {
            dfs(digits, curr+1, path+c, res);
        }
    }
};


#endif //CODE1_LETTERCOMBINATIONOFAPHONENUMBER_H
