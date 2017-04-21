//
// Created by jesse wang on 3/22/17.
//

#ifndef CODE1_PRODUCTOFARRAYEXCEPTSELF_H
#define CODE1_PRODUCTOFARRAYEXCEPTSELF_H

#include "inc_me.h"

class ProductOfArrayExceptSelf {
public:
    vector<int> product(vector<int>& nums) {
        vector<int> res;
        const int sz = nums.size();
        if (sz == 0) { return res;}

        long long f[sz+1];
        f[sz] = 1;
        for (int i= sz-1; i>=0; i--) {
            f[i] = f[i+1] * nums[i];
        }

        long long tmp =1;
        for (int i =0; i < sz; i++) {
            res.push_back(tmp * f[i+1]);
            tmp *= nums[i];
        }
        return res;
    }
};


#endif //CODE1_PRODUCTOFARRAYEXCEPTSELF_H
