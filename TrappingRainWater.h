//
// Created by jesse_wang on 4/16/2017.
//

#ifndef CODE1_TRAPPINGRAINWATER_H
#define CODE1_TRAPPINGRAINWATER_H

#include "inc_me.h"

class TrappingRainWater {
public:
    int trapRainWater(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int res = 0;
        if (left >= right)
            return res;
        int left_height = heights[left];
        int right_height = heights[right];
        while (left < right) {
            if (left_height < right_height) {
                left++;
                if (left_height > heights[left]) {
                    res += left_height-heights[left];
                } else {
                    left_height = heights[left];
                }
            } else {
                right--;
                if (right_height > heights[right]) {
                    res += right_height-heights[right];
                } else {
                    right_height = heights[right];
                }
            }
        }
        return res;
    }

};


#endif //CODE1_TRAPPINGRAINWATER_H
