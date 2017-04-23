//
// Created by jesse_wang on 3/21/2017.
//

#ifndef CODE1_MERGEINTERVALS_H
#define CODE1_MERGEINTERVALS_H

#include "inc_me.h"

class MergeIntervals {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        const int sz = intervals.size();
        if (sz == 0) { return res; }
        sort(intervals.begin(), intervals.end(), [] (const Interval& a, const Interval& b) {
            return a.start == b.start ? a.end < b.end : a.start < b.start;
        });
        res.push_back(intervals[0]);
        for (int i =1; i < sz; i++) {
            if (isOverlapped(res.back(), intervals[i])) {
                res.back().end = max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
    bool isOverlapped(const Interval& prev, const Interval& curr) {
        return prev.end >= curr.start;
    }


};


#endif //CODE1_MERGEINTERVALS_H
