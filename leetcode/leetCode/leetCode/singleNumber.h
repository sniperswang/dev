//
//  singleNumber.h
//  leetCode
//
//  Created by Yao Wang on 10/24/13.
//
//

#ifndef leetCode_singleNumber_h
#define leetCode_singleNumber_h

class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int res = A[0];
        
        for(int i = 1; i < n; i ++){
            res=res^A[i];
        }
        return res;
    }
};

/*
 
 int a[7];
 a[0] = 1;
 a[1] = 2;
 a[2] = 3;
 a[3] = 3;
 a[4] = 2;
 a[5] = 4;
 a[6] = 1;
 
 Solution s;
 
 int res = s.singleNumber(a, 7);
 
 cout << "res:" <<res <<endl;
 
 */

#endif
