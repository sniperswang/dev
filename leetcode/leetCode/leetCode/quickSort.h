//
//  quickSort.h
//  leetCode
//
//  Created by Yao Wang on 7/20/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef leetCode_quickSort_h
#define leetCode_quickSort_h

class Solution_quick_sort {
public:
    void quickSortNum(int* numArray, int len){
        quickSort(numArray,0,len-1);
    }
private:
    
    void quickSort(int *numArray, int start, int end){
        if(start < end){
            int mid = partition(numArray, start, end);
            quickSort(numArray, start, mid-1);
            quickSort(numArray, mid, end);
        }else{
            return;
        }
    }
    
    int partition(int *a, int start, int end) {
        
        int x = a[end];
        int i = start-1;
        int temp;
        
        for( int j = start; j < end; j++) {
            if ( a[j] < x ){
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        
        temp=a[i+1];
        a[i+1]=x;
        a[end]=temp;
        return i+1;
            
    }
};

#endif
