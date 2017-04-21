//
// Created by jessew on 3/18/17.
//

#ifndef CODE1_REVERSEWORDSINASTRINGII_H
#define CODE1_REVERSEWORDSINASTRINGII_H

#include "inc_me.h"

// LC 186
class ReverseWordsInAStringII {
public:
    void reverseWords(string& s) {
        const int n = s.size();
        if ( n == 0) { return; }

        reverse(s, 0, n-1);
        int start = 0;
        for (int i =0; i < n; i++) {
            if (s[i] == ' ') {
                reverse(s, start, i-1);
                start = i+1;
            }
        }
        reverse(s, start, n-1);
    }
    void reverse(string& s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};


#endif //CODE1_REVERSEWORDSINASTRINGII_H
