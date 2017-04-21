//
// Created by jesse wang on 3/22/17.
//

#ifndef CODE1_SEARCHINROTATEDSORTEDARRAY_H
#define CODE1_SEARCHINROTATEDSORTEDARRAY_H

#include "inc_me.h"

class SearchInRotatedSortedArray {
public:
    int search(vector<int>& nums, int target) {
        const int sz = nums.size();
        if (sz == 0) { return -1; }
        int start = 0, end = sz-1;
        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[start] < nums[mid]) {
                if (nums[start] <= target && target <= nums[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else {
                if (nums[mid] <= target && target <= nums[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
        }
        if (nums[start] == target) {
            return start;
        }
        if (nums[end] == target) {
            return end;
        }
        return -1;
    }

};


#endif //CODE1_SEARCHINROTATEDSORTEDARRAY_H
