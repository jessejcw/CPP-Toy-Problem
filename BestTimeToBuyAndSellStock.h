//
// Created by jesse_wang on 2/18/2017.
//

#ifndef CODING1_BESTTIMETOBUYANDSELLSTOCK_H
#define CODING1_BESTTIMETOBUYANDSELLSTOCK_H

#include "inc_me.h"

// 121. Best Time to Buy and Sell Stock
class BestTimeToBuyAndSellStock {
public:
    int maxProfit(vector<int>& prices) {

        int min_val = INT_MAX;
        int max_profit = 0;
        for(int p : prices) {
            min_val = min(p, min_val);
            max_profit = max(max_profit, p - min_val);
        }
        return max_profit;
    }
};


#endif //CODING1_BESTTIMETOBUYANDSELLSTOCK_H
