//
//  canJump.h
//  leetCode
//
//  Created by Yao Wang on 2/15/14.
//
//

#ifndef leetCode_canJump_h
#define leetCode_canJump_h

class Solution {
public:
    bool canJump(int A[], int n) {
        
        if (n == 0 || n ==1 ) {
            return true;
        }
        
        int extraStep = 0; ;
        for(int i = n-2; i > 0; --i) {
            int minStep = extraStep + 1;
            
            if(A[i] < minStep) {
                extraStep++;
            } else {
                extraStep = 0; //reset
            }
            
        }
        
        if( A[0] <  extraStep + 1) {
            return false;
        } else {
            return true;
        }
        
    }
};

/*
 
 int A []= {1,2,0,1};
 
 Solution s;
 
 cout << "res:" << s.canJump(A,4)<< endl;
 
 
 */

#endif
