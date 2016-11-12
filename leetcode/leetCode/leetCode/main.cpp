//
//  main.cpp
//  leetCode
//
//  Created by Yao Wang on 6/14/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <sstream>
#include "staticExample.h"
#include <math.h> 
#include <iomanip>
#include <queue>
#include <deque>


using namespace std;

/*
class Solution {
public:
    int search(int A[], int n, int target) {
        int L = 0;
        int R = n - 1;
        
        while( L <= R )
        {
            cout << "L:" <<L<< " R:" << R << endl;
            int M = L + (R-L)/2;
         
            if (A[M] == target)
            {
                return M;
            }
            
            if ( A[L] <= A[M] )
            {
                if (A[L] <= target && target < A[M] )
                {
                    R = M - 1;
                } else
                {
                    L = M + 1;
                }
            }
            else
            {
                if ( A[M] < target && target <= A[R])
                {
                    L = M + 1;
                } else
                {
                    R = M -1;
                }
            }
            
        }
        
        return -1;
        
    }
};
 */





int main (int argc, const char * argv[])
{
    
    cout << " hello world" << endl;
    return 0;
}

