//
//  climbStairs.h
//  leetCode
//
//  Created by Yao Wang on 2/19/14.
//
//

#ifndef leetCode_climbStairs_h
#define leetCode_climbStairs_h

class Solution {
public:
    int climbStairs(int n) {
        
        if( n == 0) {
            return 0;
        }
        
        int prev_numOfones = 1;
        int prev_steps = 1;
        int step = 1;
        
        
        for (int i = 1; i < n ; i++) {
            step = prev_steps + prev_numOfones;
            prev_numOfones = prev_steps;
            prev_steps = step;
        }
        
        
        return step;
    }
    
};

/*
 
 int steps = 0;
 
 Solution s;
 steps = s.climbStairs(5);
 
 cout << " steps: " << steps << endl;
 
 
 */


#endif
