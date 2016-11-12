//
//  removeDuplicates.h
//  leetCode
//
//  Created by Yao Wang on 2/22/14.
//
//

#ifndef leetCode_removeDuplicates_h
#define leetCode_removeDuplicates_h

/*
 
 Remove Duplicates from Sorted Array
 
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 
 Do not allocate extra space for another array, you must do this in place with constant memory.
 
 For example,
 Given input array A = [1,1,2],
 
 Your function should return length = 2, and A is now [1,2].
 
 */


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        
        int proceed = 0;
        int newLen = n;
        if(n == 0 || n == 1) {
            return n;
        }
        
        int chkElement = A[0];
        
        for(int i = 1; i < n; i++) {
            if(A[i] == chkElement) {
                proceed++;
                newLen--;
            } else {
                
                chkElement = A[i] ;
                A[i-proceed] = A[i];
            }
        }
        
        return newLen;
    }
};

/*
 
 int A[] = {1,1,2,2,3,3,4};
 
 Solution s;
 
 int newLen = s.removeDuplicates(A, 7);
 
 for(int i = 0; i < newLen; i++) {
 cout <<" "<<A[i];
 }
 cout<<endl;
 
 */

#endif
