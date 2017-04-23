//
// Created by jesse_wang on 3/2/2017.
//

#ifndef CODING1_REMOVEINVALIDPARENTHESES_H
#define CODING1_REMOVEINVALIDPARENTHESES_H

#include "inc_me.h"
//http://www.geeksforgeeks.org/remove-invalid-parentheses/
//
class RemoveInvalidParentheses {
public:
    void removeInvalidParenthesis(string str) {
        if (str.empty()) {
            return;
        }
        set<string> visit;

        queue<string> q;
        string temp;
        bool level;

        q.push(str);
        visit.insert(str);

        while (!q.empty()) {
            str = q.front();
            q.pop();
            if (isValidString(str)) {
                cout << str << endl;
                level = true;
            }
            if (level)
                continue;
            for (int i =0 ; i< str.size(); i++) {
                if (!isParenthesis(str[i]))
                    continue;
                temp = str.substr(0, i) + str.substr(i+1);
                if (visit.find(temp) == visit.end()) {
                    q.push(temp);
                    visit.insert(temp);
                }
            }
        }

    }
    bool isParenthesis(char& c) {
        return (c=='(') || (c==')');
    }
    bool isValidString(string& str) {
        int cnt = 0;
        for (int i=0; i<str.size(); i++) {
            if (str[i] == '(')
                cnt++;
            else if (str[i] == ')')
                cnt--;
            if (cnt <0)
                return false;
        }
        return cnt == 0;
    }

};


#endif //CODING1_REMOVEINVALIDPARENTHESES_H
