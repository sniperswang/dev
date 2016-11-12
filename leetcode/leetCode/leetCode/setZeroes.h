//
//  setZeroes.h
//  leetCode
//
//  Created by Yao Wang on 2/8/14.
//
//

#ifndef leetCode_setZeroes_h
#define leetCode_setZeroes_h

class Solution {
public:
    
    void setZeroes(vector<vector<int> > &matrix) {
        
        const unsigned long y_len = matrix.size();
        const unsigned long x_len = matrix[0].size();
        
        bool is_y_zero = false;
        bool is_x_zero = false;
        
        for(int i = 0; i < y_len; i ++) {
            if (matrix[i][0] == 0) {
                is_y_zero = true;
                break;
            }
        }
        
        for(int j = 0; j < x_len; j++) {
            if (matrix[0][j] == 0) {
                is_x_zero = true;
                break;
            }
        }
        
        for(int i = 1; i < y_len; i ++) {
            for (int j = 1; j < x_len; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        
        for(int i = 1; i < y_len; i++) {
            if(matrix[i][0] == 0) {
                for (int j = 1; j < x_len; j++ ) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int j = 1; j < x_len; j++) {
            if(matrix[0][j] == 0) {
                for (int i = 1; i < y_len; i++ ) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(is_y_zero) {
            for(int i = 0; i < y_len; i++) {
                matrix[i][0] = 0;
            }
        }
        
        if(is_x_zero) {
            for(int j = 0; j < x_len; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};


/*
 
 vector<int> x_0;
 x_0.push_back(0);
 x_0.push_back(1);
 
 vector<vector<int> > matrix;
 
 matrix.push_back(x_0);
 
 Solution s;
 s.setZeroes(matrix);
 
 const unsigned long y_len = matrix.size();
 const unsigned long x_len = matrix[0].size();
 
 for (int i = 0; i < y_len; i++) {
 for(int j = 0; j < x_len; j++) {
 cout <<" "<< matrix[i][j];
 }
 cout << endl;
 }
 
 */

#endif
