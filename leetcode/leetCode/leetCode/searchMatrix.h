//
//  searchMatrix.h
//  leetCode
//
//  Created by Yao Wang on 8/31/13.
//
//

#ifndef leetCode_searchMatrix_h
#define leetCode_searchMatrix_h

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int x_len = matrix[0].size();
        int y_len = matrix.size();
        
        int x = x_len - 1;
        int y = 0;
        while(x >= 0 && y < y_len) {
            if(target == matrix[y][x])
            {
                return true;
            }
            
            if(target < matrix[y][x] ) {
                x-- ;
            } else {
                y++;
            }
            
        }
        
        return false;
        
    }
};

/*
 // vector<int> x1;
 int x1[] = {1,3,5,7};
 int x2[] = {10, 11, 16, 20};
 int x3[] = {23, 30, 34, 50};
 vector<int> v1(x1, x1 + 4);
 vector<int> v2(x2, x2 + 4);
 vector<int> v3(x3, x3 + 4);
 
 vector< vector<int> > matrix;
 matrix.push_back(v1);
 matrix.push_back(v2);
 matrix.push_back(v3);
 
 Solution s;
 bool res = s.searchMatrix(matrix, 25);
 
 cout << "res: " <<res << "\n";
 
 */

#endif
