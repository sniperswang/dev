//
//  singleNumber2.h
//  leetCode
//
//  Created by Yao Wang on 10/24/13.
//
//

#ifndef leetCode_singleNumber2_h
#define leetCode_singleNumber2_h

class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int one = 0, two = 0;
        for (int i = 0; i < n; i++) {
            int one_ = (one ^ A[i]) & ~two;
            int two_ = (A[i] & one) | (~A[i] & two);
            
            //  cout << "A["<<i<<"]:"<<A[i] <<endl;
            cout << "one_:" << one_ <<endl;
            cout << "two_:" << two_ <<endl;
            cout << "~A[i] & two:" << (~A[i] & two) <<endl;
            cout << endl;
            one = one_;
            two = two_;
        }
        
        return two;
    }
};


/*
 
 int a[8];
 a[0] = 1;
 a[1] = 1;
 a[2] = 1;
 a[3] = 3;
 a[4] = 3;
 a[5] = 3;
 a[6] = 2;
 
 Solution s;
 
 int res = s.singleNumber(a, 7);
 
 cout << "res:" <<res <<endl;

 
 
 */

#endif
