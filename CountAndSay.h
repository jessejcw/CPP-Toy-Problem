//
// Created by jesse wang on 3/22/17.
//

#ifndef CODE1_COUNTANDSAY_H
#define CODE1_COUNTANDSAY_H

#include "inc_me.h"

class CountAndSay {
public:
    string countAndSay(int n) {
        if (n < 1) { return ""; }
        string res = "1";
        for (int i = 2; i <= n; i++) {
            string tmp = "";
            int count = 1;
            char prev = res[0];
            for ( int j =1; j < res.size(); j++) {
                if (res[j] == prev) {
                    count++;
                } else {
                    tmp += to_string(count);
                    tmp.push_back(prev);
                    count = 1;
                    prev = res[j];
                }
            }
            tmp += to_string(count);
            tmp.push_back(prev);
            res = tmp;
        }
        return res;
    }
};


#endif //CODE1_COUNTANDSAY_H
