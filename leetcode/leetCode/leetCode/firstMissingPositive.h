//
//  firstMissingPositive.h
//  leetCode
//
//  Created by Yao Wang on 9/18/13.
//
//

#ifndef leetCode_firstMissingPositive_h
#define leetCode_firstMissingPositive_h


class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(n <= 0)
            return 1;
        int intOutOfRange = n + 2;
        //first run, turn every negetive value into an impossible positive value
        //make every value in A is positive
        for(int i = 0 ; i < n ; ++ i) {
            if(A[i] <= 0)
                A[i] = intOutOfRange;
        }
        //second run, make A[] as a hash table, A[i] indicate the presence of i + 1
        //the way is that, if k in [1,n] is in A[], then turn A[k -1] to negetive
        for(int i = 0 ; i < n ; ++i) {
            int ai = A[i];
            int absi = abs(ai);
            if(absi <= n)
                A[absi-1] = -abs(A[absi-1]);
        }
        //third run, if A[i] is positive, from step 2, we know that i + 1 is missing.
        for(int i = 0 ; i < n ; ++i) {
            if(A[i] > 0)
                return i + 1;
        }
        //all int from 1 to n is present, then return n + 1
        return n+1;
    }
    
};

/*
 //int arr[] = {0, 10, 2, -10, -20};
 // int arr[] = { 2, 3, -7, 6, 8, 1, -10, 15 };
 int arr[] = {2,2};
 int arr_size = sizeof(arr)/sizeof(arr[0]);
 
 Solution s;
 int missing = s.firstMissingPositive(arr, arr_size);
 
 cout << "missing :" << missing << endl;
 
 */

#endif
