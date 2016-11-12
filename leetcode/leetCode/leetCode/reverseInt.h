//
//  reverseInt.h
//  leetCode
//
//  Created by Yao Wang on 7/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
#include <stdlib.h>  
#ifndef leetCode_reverseInt_h
#define leetCode_reverseInt_h

class Solution_reverse_int {
public:
    int reverseInt(int num){
        int res = 0;
        if (abs(num) < 10 )
            return num;
        while(num != 0){
            int dight = num % 10;
            res = res*10 + dight;
            num = num / 10;
        }
        return res;
    }
};

#endif
