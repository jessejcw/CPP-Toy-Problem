//
// Created by jesse_wang on 3/21/2017.
//

#ifndef CODING1_MULTIPLYSTRING_H
#define CODING1_MULTIPLYSTRING_H

#include "inc_me.h"

class MultiplyString {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        if (m * n == 0)  {return ""; }
        vector<int> digits( m+n, 0);
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                int product = (num1[i]-'0') * (num2[j]-'0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = product + digits[p2];
                digits[p1] += sum / 10;
                digits[p2] = sum % 10;
            }
        }
        stringstream ss;
        for (int digit : digits) {
            if (!(ss.str().size() == 0 && digit == 0))
                ss << digit;
        }
        return ss.str().size() == 0 ? "0" : ss.str();

    }
};


#endif //CODING1_MULTIPLYSTRING_H
