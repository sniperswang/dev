//
//  mergeTwoArray.h
//  leetCode
//
//  Created by Yao Wang on 11/9/13.
//
//

#ifndef leetCode_mergeTwoArray_h
#define leetCode_mergeTwoArray_h

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (n ==0) {
            return;
        }
        
        if( m==0 && n!=0 ) {
            copy(B, B+n, A);
            return;
        }
        
        
        int posA = m-1;
        int posB = n-1;
        
        int posTol = m+n-1;
        
        while(posA >= 0 && posB >= 0) {
            if(A[posA] > B[posB]) {
                A[posTol] = A[posA];
                posA -- ;
            } else {
                A[posTol] = B[posB];
                posB -- ;
            }
            posTol--;
        }
        
        if(posA < 0 && posB >= 0) {
            copy(B, B+posB+1, A);
        }
    }
    
};

/*
 
 
 int A[20] = {1,2,3,5,8};
 int B[3]  = {4,7,10};
 
 Solution s;
 
 s.merge(A, 5, B, 3);
 
 for(int i = 0; i < 8; i++) {
 cout << A[i] << " ";
 }
 
 cout << endl;
 
 */


#endif
