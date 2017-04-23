//
// Created by jesse_wang on 2/26/2017.
//

#ifndef CODING1_HIGHFIVE_H
#define CODING1_HIGHFIVE_H

#include "inc_me.h"
struct Record {
    int id, score;
    Record(int id, int score) : id(id), score(score){}
};

class HighFive {

public:
    map<int, double> highFive(vector<Record> results) {
        map<int, priority_queue<int>> hash;
        for (auto it: results) {
            hash[it.id].push(it.score);
        }
    }

};


#endif //CODING1_HIGHFIVE_H
