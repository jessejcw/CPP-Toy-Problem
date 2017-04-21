//
// Created by jesse wang on 3/22/17.
//

#ifndef CODE1_SKYLINE_H
#define CODE1_SKYLINE_H

#include "inc_me.h"

class Skyline {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buidlings) {
        vector<pair<int, int>> res;
#if 0
        int cur=0, cur_x, cur_h, len = buidlings.size();
        priority_queue<pair<int, int>> bldg;
        while (cur < len || !bldg.empty()) {
            if (bldg.empty() || cur < len && buidlings[cur][0] <= bldg.top().second) {
                cur_x = buidlings[cur][0];
                while
            }
        }
#endif
        return res;
    }

};


#endif //CODE1_SKYLINE_H
