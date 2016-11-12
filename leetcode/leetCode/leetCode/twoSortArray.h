//
//  twoSortArray.h
//  leetCode
//
//  Created by Yao Wang on 7/10/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef leetCode_twoSortArray_h
#define leetCode_twoSortArray_h

/*
 Median of Two Sorted ArraysMar 28 '113616 / 18710
 There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

class Solution_Two_Sorted_array {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int index_1 = -1;
        int index_2 = -1;
        
        if ( ((m+n) %2) == 0){
            index_1 = ((m+n)/2)-1;
            index_2 = (m+n)/2;
        } else {
            index_1 = (m+n) / 2;
        }
        int i = 0;
        int last_small = 0;
        int pos_a = 0;
        int pos_b = 0;
        while(true){
            int a=0;
            int b=0;
            if(pos_a < m){
                a=A[pos_a];
            }else{
                a=B[pos_b] + 1;
            }
            
            if(pos_b < n){
                b=B[pos_b];
            }else{
                b=A[pos_a] + 1;
            }
            
            if(i == index_1 && index_2 == -1){
                if(a < b)
                    return a;
                else 
                    return b;
            }
            
            if(i == index_2){
                if (a < b)
                    return (double(a)+double(last_small) )/ double(2);
                else
                    return (double(b)+double(last_small) )/ double(2);
            }
            
            if(a < b){
                last_small = a;
                pos_a++;
            }else {
                last_small = b;
                pos_b++;
                
            }
            i++;
        }  
    }
};


#endif
