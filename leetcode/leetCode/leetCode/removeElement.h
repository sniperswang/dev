//
//  removeElement.h
//  leetCode
//
//  Created by Yao Wang on 2/22/14.
//
//

#ifndef leetCode_removeElement_h
#define leetCode_removeElement_h

/*
 
 Remove Element
 Given an array and a value, remove all instances of that value in place and return the new length.
 
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 
 */



class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int proceed = 0;
        int len = n;
        for ( int i =0; i < n; i++ ) {
            if(A[i] != elem) {
                A[i-proceed] = A[i];
            } else {
                proceed++;
                len--;
            }
        }
        
        return len;
    }
};


/*
 int A[] = {1,1,2,3,1,2,4};
 
 Solution s;
 
 int newLen = s.removeElement(A, 7, 1);
 
 for(int i = 0; i < newLen; i++) {
 cout <<" "<<A[i];
 }
 cout<<endl;
 
 */


#endif
