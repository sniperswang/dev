//
//  maxSubArray.h
//  leetCode
//
//  Created by Yao Wang on 9/23/13.
//
//

#ifndef leetCode_maxSubArray_h
#define leetCode_maxSubArray_h


class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if( n == 0) {
            return 0;
        }
        
        int maxSub = A[0];
        int preSubVal = A[0];
        for(int i = 1; i < n ; i++) {
            int sum = A[i] + preSubVal;
            if(sum > A[i] ) {
                preSubVal = sum;
            } else {
                preSubVal = A[i];
            }
            
            if(preSubVal > maxSub)
                maxSub=preSubVal;
        }
        
        return maxSub;
    }
};

/*
 //int myints[9] = {-2,1,-3,4,-1,2,1,-5,4};
 int myints[2] = {-2,1};
 Solution s;
 int max = s.maxSubArray(myints,sizeof(myints) / sizeof(int)  );
 cout << "max :" << max <<endl;
 */
#endif
