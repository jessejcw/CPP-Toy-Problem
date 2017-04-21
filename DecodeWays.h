//
// Created by jesse wang on 3/14/17.
//

#ifndef CODE1_DECODEWAYS_H
#define CODE1_DECODEWAYS_H

#include "inc_me.h"

class DecodeWays {
public:
    int numDecodings(string s) {
        if (s.size()==0) { return 0;}
        vector<int> nums(s.size()+1);
        nums[0] = 1;
        nums[1] = s[0] != '0' ? 1 : 0;
        for (int i =2; i <= s.size(); i ++) {
            if (s[i-1] != '0') {
                nums[i] = nums[i-1];
            }
            int two_digits = (s[i-2] -'0') * 10 + s[i-1] -'0';
            if (two_digits >= 10 && two_digits <=26) {
                nums[i] += nums[i-2];
            }
        }
        return nums[s.size()];
    }
};


#endif //CODE1_DECODEWAYS_H
