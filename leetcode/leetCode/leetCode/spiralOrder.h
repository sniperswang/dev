//
//  spiralOrder.h
//  leetCode
//
//  Created by Yao Wang on 9/28/13.
//
//

#ifndef leetCode_spiralOrder_h
#define leetCode_spiralOrder_h

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> res;
        
        if(matrix.size() == 0 )
            return res;
        
        helper(matrix, matrix.size(), matrix[0].size(), 0, res);
        return res;
    }
    
    void helper(vector<vector<int> > &matrix, int m, int n, int k, vector<int>& res){
        if(m <=0 || n <=0)
            return;
        
        if(m == 1) {
            for(int j = 0; j < n; j++) {
                res.push_back(matrix[k][k+j]);
            }
            return;
        }
        
        if(n == 1) {
            for(int i = 0; i < m; i++) {
                res.push_back(matrix[k+i][k]);
            }
            return;
        }
        
        // from top left
        for(int j=0; j < n - 1; j++) {
            res.push_back(matrix[k][k+j]);
        }
        
        // from top right
        for(int i =0; i < m - 1; i++ ) {
            res.push_back(matrix[k+i][k+n-1]);
        }
        
        // from bottom right
        for(int j =0; j < n -1; j++) {
            res.push_back(matrix[k+m-1][k+n-1-j]);
        }
        
        // for bottom left
        for(int i =0; i < m -1; i++){
            res.push_back(matrix[k+m-1-i][k]);
        }
        
        helper(matrix,m-2,n-2,k+1,res);
        
    }
};

/*
 
 vector< vector<int> > val;
 
 vector<int> a;
 vector<int> b;
 
 a.push_back(3);
 b.push_back(2);
 
 val.push_back(a);
 val.push_back(b);
 
 
 Solution s;
 
 vector<int> res = s.spiralOrder(val);
 
 
 for( int i = 0; i < res.size(); i ++) {
 cout << res[i] << " " ;
 }
 cout << endl;
 
 */

#endif
