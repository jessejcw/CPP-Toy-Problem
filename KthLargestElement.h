//
// Created by jesse_wang on 3/18/2017.
//

#ifndef CODE1_KTHLARGESTELEMENT_H
#define CODE1_KTHLARGESTELEMENT_H

#include "inc_me.h"

class KthLargestElement {
public:
    int findKthElement(vector<int>& nums, int k) {
        const int sz = nums.size();
        if (sz == 0) { return -1; }
        return quickSelect(nums, 0, sz-1, k);
    }
    int quickSelect(vector<int>& nums, int start, int end, int k) {
        if (start == end) {
            return nums[start];
        }

        int i = start, j = end;
        int pivot = nums[(i+j)/2];
        while (i <= j) {
            while (i <= j && nums[i] > pivot) {
                i++;
            }
            while (i <= j && nums[i] < pivot) {
                j--;
            }
            if (i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        if (start + k -1 <= j) {
            return quickSelect(nums, start, j, k);
        }

        if (start + k -1 >= i) {
            return quickSelect(nums, i, end, k - (i-start));
        }

        return nums[j+1];
    }
};


#endif //CODE1_KTHLARGESTELEMENT_H
