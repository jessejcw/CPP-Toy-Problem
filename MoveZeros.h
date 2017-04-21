//
// Created by jessew on 3/18/17.
//

#ifndef CODE1_MOVEZEROS_H
#define CODE1_MOVEZEROS_H

#include "inc_me.h"

class MoveZeros {
public:
    void moveZeros(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) { return;}
        int idx =0;
        for (int i =0; i < n; i++) {
            if (nums[i] != 0) {
                if (nums[i] != nums[idx]) {
                    swap(nums[i], nums[idx]);
                }
                idx++;
            }
        }
    }

};


#endif //CODE1_MOVEZEROS_H
