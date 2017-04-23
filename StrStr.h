//
// Created by jesse_wang on 3/22/2017.
//

#ifndef CODE1_STRSTR_H
#define CODE1_STRSTR_H

#include "inc_me.h"

class StrStr {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.size(), nlen = needle.size();
        for (int i= 0; i < hlen-nlen+1; i++) {
            int j= 0;
            for (; j< nlen; j++) {
                if (haystack[i+j] != needle[j])
                    break;
            }
            if (j == nlen) {
                return i;
            }
        }
        return -1;
    }
    static const int BASE = 1000000;
    int strstrII(string haystack, string needle) {
        const int m = needle.size();
        const int n = haystack.size();
        int power = 1;
        for (int i =0; i < m; i++) {
            power = (power*31) % BASE;
        }

        int target_hash = 0;
        for (int i =0; i < m ;i++) {
            target_hash = ((target_hash*31)+needle[i]) % BASE;
        }

        int hash_code = 0;
        for (int i =0; i< n; i++) {
            hash_code = ((hash_code*31)+haystack[i]) % BASE;
            if ( i < m -1) {
                continue;
            }
            if (i >= m) {
                hash_code = hash_code - (haystack[i-m] * power) % BASE;
                if (hash_code < 0)
                    hash_code += BASE;
            }

            if (hash_code == target_hash) {
                if (haystack.substr(i-m+1, m) == needle)
                    return i-m+1;
            }
        }
        return -1;
    }
};


#endif //CODE1_STRSTR_H
