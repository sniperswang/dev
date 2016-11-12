//
//  searchInsert.h
//  leetCode
//
//  Created by Yao Wang on 2/18/14.
//
//

#ifndef leetCode_searchInsert_h
#define leetCode_searchInsert_h



 
 class Solution {
 public:
     int searchInsert(int A[], int n, int target) {
     
         if (n == 0) {
             return 0;
         }
         
         if (target > A[n-1]) {
             return n;
         }
         
         int mid = n / 2;
         
         if (A[mid] == target) {
             return mid;
         } else if (target < A[mid] ) {
             return binarySearch(A,0,mid,target);
         } else {
             return binarySearch(A,mid+1,n-1,target);
         }
     
         return 0;
     }
     
private:
     int binarySearch(int A[], int s, int e, int target) {
     
         if( s >= e) {
             return e;
         }
         
         int mid = (e-s) / 2;
         
         if (A[s+mid] == target ) {
             return s+mid;
         } else if (target < A[s+mid] ){
             return binarySearch(A, s, s+mid, target);
         } else {
             return binarySearch(A, s+mid+1, e, target);
         }
         
         return 0;
     }
 
 };
 
 /*
  int A[] = {1,2,4,6,8,9,10};
  
  Solution s;
  
  int pos = s.searchInsert(A,7,10 );
 */

#endif
