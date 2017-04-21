//
// Created by jesse wang on 3/22/17.
//

#ifndef CODE1_INSERINTERVAL_H
#define CODE1_INSERINTERVAL_H

#include "inc_me.h"

class InserInterval {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        const int sz = intervals.size();
        if (sz == 0) {
            res.push_back(newInterval);
            return res;
        }
        int ins_pos = 0;
        for (Interval curr : intervals) {
            if (curr.end < newInterval.start) {
                ins_pos++;
                res.push_back(curr);
            } else if (newInterval.end < curr.start) {
                res.push_back(curr);
            } else {
                newInterval.start = min(newInterval.start, curr.start);
                newInterval.end = max(newInterval.end, curr.end);
            }
        }
        res.insert(res.begin()+ins_pos, newInterval);
        return res;
    }

};


#endif //CODE1_INSERINTERVAL_H
