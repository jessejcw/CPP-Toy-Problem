//
// Created by jesse wang on 3/21/17.
//

#ifndef CODE1_MULTIPLYSTRINGS_H
#define CODE1_MULTIPLYSTRINGS_H

#include "inc_me.h"

class MultiplyStrings {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        if (m * n == 0) { return "";}

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res( m+n, '0');
        for (int i =0; i < m; i++) {

        }
    }

};


#endif //CODE1_MULTIPLYSTRINGS_H
