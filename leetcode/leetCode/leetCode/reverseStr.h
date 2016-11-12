//
//  reverseStr.h
//  leetCode
//
//  Created by Yao Wang on 7/10/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "staticExample.h"

#ifndef leetCode_reverseStr_h
#define leetCode_reverseStr_h

/***
 
 reverse a string / char array[];
 
 */

class Solution_reverse_str {
public:
    void reverseStr(char *str){
        int len = strlen(str);
        char temp;
        for(int i = 0, j = len - 1; i < j; i++, j--){
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
};



#endif
