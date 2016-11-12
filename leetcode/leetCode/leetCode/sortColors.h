//
//  sortColors.h
//  leetCode
//
//  Created by Yao Wang on 1/18/14.
//
//

#ifndef leetCode_sortColors_h
#define leetCode_sortColors_h

class Solution {
public:
    void sortColors(int A[], int n) {
        
        int n_red = 0;
        int n_white = 0;
        int n_blue = 0;
        
        
        for (int i = 0; i < n ; i++ ) {
            int color = A[i];
            
            switch (color) {
                case 0 : {n_red++; break;}
                case 1 : {n_white++; break;}
                case 2 : {n_blue++; break;}
                default: {break;}
            }
        }
        int j = 0;
        for(int i = 0; i < n_red; i++) {
            A[j] = 0;
            j++;
        }
        
        for (int i= 0; i < n_white; i++) {
            A[j] = 1;
            j++;
        }
        
        for (int i= 0; i < n_blue; i++) {
            A[j] = 2;
            j++;
        }
    }
};



#endif
