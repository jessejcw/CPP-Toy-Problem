//
// Created by jesse wang on 3/14/17.
//

#ifndef CODE1_MEETINGROOMII_H
#define CODE1_MEETINGROOMII_H

#include "inc_me.h"

class MeetingRoomII {
public:
    int minMeetingRooms(vector<Interval>& intervals ) {
        map<int, int> mp; // start, end -> count
        for (Interval item : intervals) {
            mp[item.start]++;
            mp[item.end]--;
        }

        int curr = 0, max_room = 0;
        for (auto itr : mp) {
            curr += itr.second;
            max_room = max(max_room, curr);
        }
        return max_room;
    }
};


#endif //CODE1_MEETINGROOMII_H
