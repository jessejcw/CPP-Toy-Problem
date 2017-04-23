//
// Created by jesse_wang on 2/18/2017.
//

#ifndef CODING1_SLIDINGWINDOWMAXIMUM_H
#define CODING1_SLIDINGWINDOWMAXIMUM_H

#include "inc_me.h"
// 239. Sliding Window Maximum
class SlidingWindowMaximum {
    void inQueue(deque<int>& que, int num) {
        while (!que.empty() && que.back() < num) {
            que.pop_back();
        }
        que.push_back(num);
    }

    void outQueue(deque<int>& que, int num) {
        if (que.front() == num) {
            que.pop_front();
        }
    }
public:
    vector<int> maxSlidginWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> res;

        for (int i = 0; i < k -1; i++) {
            inQueue(que, nums[i]);
        }

        for(int i = k -1; i < nums.size(); i++) {
            inQueue(que, nums[i]);
            res.push_back(move(que.front()));
            outQueue(que, nums[i-k+1]);
        }
        return res;
    }
};


#endif //CODING1_SLIDINGWINDOWMAXIMUM_H
