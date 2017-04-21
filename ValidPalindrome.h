//
// Created by jesse wang on 3/21/17.
//

#ifndef CODE1_VALIDPALINDROME_H
#define CODE1_VALIDPALINDROME_H

#include "inc_me.h"

class ValidPalindrome {
public:
    bool isPalindrome(string s) {
        const int sz = s.size();
        if (sz == 0) { return true; }
        int left = 0, right = sz-1;
        while (left < right) {
            while (left < right && !in_range(s[left])) {
                left++;
            }
            while (left < right && !in_range(s[right])) {
                right--;
            }
            if (!is_equal(s[left], s[right])) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
    bool in_range(char& c) {
        if (c >= 'A' && c <= 'Z')
            return true;
        if (c >= 'a' && c <= 'z')
            return true;
        if (c >= '0' && c <= '9')
            return true;
        return false;
    }
    bool is_equal(char& a, char& b) {
        if (a==b) {
            return true;
        }
        if (a >= 'a' && a <= 'z') {
            return (a-'a'+'A') == b;
        }
        if (b >= 'a' && b <= 'z') {
            return (b-'a'+'A') == a;
        }
        return false;
    }
};


#endif //CODE1_VALIDPALINDROME_H
