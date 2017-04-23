//
// Created by jesse_wang on 3/23/2017.
//

#ifndef CODE1_LFUCACHE_H
#define CODE1_LFUCACHE_H

#include "inc_me.h"

class LFUCache {
public:
    int cap;
    int size;
    int minFreq;
    unordered_map<int, pair<int, int>> mp; // key to {value, freq}
    unordered_map<int, list<int>::iterator> mIter; // key to list iterator
    unordered_map<int, list<int>> fm; // freq to key list

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    int get(int key) {
        if (mp.count(key) == 0) {
            return -1;
        }
        fm[mp[key].second].erase(mIter[key]);
        mp[key].second++;
        fm[mp[key]]
    }

};


#endif //CODE1_LFUCACHE_H
