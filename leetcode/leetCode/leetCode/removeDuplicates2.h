//
//  removeDuplicates2.h
//  leetCode
//
//  Created by Yao Wang on 2/22/14.
//
//

#ifndef leetCode_removeDuplicates2_h
#define leetCode_removeDuplicates2_h

/*
 
 Remove Duplicates from Sorted Array II
 
 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?
 
 For example,
 Given sorted array A = [1,1,1,2,2,3],
 
 Your function should return length = 5, and A is now [1,1,2,2,3].
 
 */


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        
        int proceed = 0;
        int newLen = n;
        
        if(n == 0 || n == 1 || n == 2) {
            return n;
        }
        
        int chkElement = A[0];
        int counter = 1;
        
        for(int i = 1; i < n; i++) {
            if(A[i] == chkElement) {
                counter++;
                if( counter > 2) {
                    proceed++;
                    newLen--;
                } else {
                    chkElement = A[i] ;
                    A[i-proceed] = A[i];
                }
                
            } else {
                chkElement = A[i] ;
                A[i-proceed] = A[i];
                counter = 1;
            }
        }
        
        return newLen;
    }
};

/*
 
 int A[] = {1,1,1,2,2,3};
 
 Solution s;
 
 int newLen = s.removeDuplicates(A, 6);
 
 for(int i = 0; i < newLen; i++) {
 cout <<" "<<A[i];
 }
 cout<<endl;
 
 */

#endif
