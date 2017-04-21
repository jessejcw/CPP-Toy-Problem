//
// Created by jesse wang on 3/13/17.
//

#ifndef CODE1_INTEGERTOENGLISH_H
#define CODE1_INTEGERTOENGLISH_H

#include "inc_me.h"

class IntegerToEnglish {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return convert(num).substr(1);

    }
    string convert(int num) {
        if (num >= 1000000000) {
            return convert(num/1000000000) + " Billion" + convert(num-1000000000*(num/10000000000));
        }
        if (num >= 1000000)
            return convert(num/1000000) + " Million" + convert(num-1000000*(num/1000000));
        if (num >= 1000)
            return convert(num/1000) + " Thousand" + convert(num-1000*(num/1000));
        if (num >= 100)
            return convert(num/100) +  " Hundred" + convert(num-100*(num/100));
        if (num >= 20)
            return " " + above20[num/10-2] + convert(num-10*(num/10));
        if (num>= 1)
            return " " + below20[num-1];
        return "";

    }
    string above20[8] = {"Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string below20[19] = {"Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                          "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

};


#endif //CODE1_INTEGERTOENGLISH_H
