//
// Created by jesse_wang on 4/9/2017.
//

#ifndef CODE1_LRUCACHE_H
#define CODE1_LRUCACHE_H

#include "inc_me.h"

class LRUCache {
    list<pair<int, int>> PList;
    unordered_map<int, list<pair<int, int>>::iterator> cache; // key ->itr
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        auto itr = cache.find(key);
        if (itr == cache.end()) {
            PList.splice(PList.begin(), PList, itr->second);
        }

    }
    void set(int key, int val) {

    }
};


#endif //CODE1_LRUCACHE_H
