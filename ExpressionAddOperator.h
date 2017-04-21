//
// Created by jessew on 3/17/17.
//

#ifndef CODE1_EXPRESSIONADDOPERATOR_H
#define CODE1_EXPRESSIONADDOPERATOR_H

#include "inc_me.h"

class ExpressionAddOperator {
public:
    vector<string> addOperator(string num, int target) {
        vector<string> res;
        const int sz = num.size();
        if ( sz == 0) { return res; }

        addOper(res, num, target, 0, "", 0);
        return res;
    }
    void addOper(vector<string>& res, string num, long target, int pos, string path, long prev) {
        if (pos == num.size() && target == 0) {
            res.push_back(path);
        } else {
            for (int i = pos; i < num.size(); i++) {
                if (num[pos] == 0 && i > pos) {
                    break;
                }
                string tmp = num.substr(pos, i-pos+1);
                long curr = stol(tmp.c_str());
                if (pos == 0) {
                    addOper(res, num, target-curr, i+1, tmp, curr);
                } else {
                    addOper(res, num, target-curr, i+1, path+"+"+tmp, curr);
                    addOper(res, num, target+curr, i+1, path+"-"+tmp, -curr);
                    addOper(res, num, target+prev-prev*curr, i+1, path+"*"+tmp, prev*curr);
                }
            }
        }
    }

};


#endif //CODE1_EXPRESSIONADDOPERATOR_H
