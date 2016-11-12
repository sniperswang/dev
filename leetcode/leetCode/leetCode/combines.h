//
//  combines.h
//  leetCode
//
//  Created by Yao Wang on 11/9/13.
//
//

#ifndef leetCode_combines_h
#define leetCode_combines_h

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<vector<int> > res;
        vector<int> check;
        vector<int> num;
        if ( k == 0) {
            res;
        }
        
        for( int i = 1; i < n + 1; i ++) {
            num.push_back(i);
        }
        
        for(int i = 0; i < num.size(); i++) {
            check.push_back(0);
        }
        
        int count = 0;
        vector<int> e;
        helper(num,check,res,e,count,k);
        return res;
        
    }
    
    
    void helper(vector<int> &num, vector<int> check, vector<vector<int> > &res, vector<int> e, int count, int max) {
        for( int i = 0; i < check.size(); i++ ) {
            if(check[i] == 0) {
                check[i] = 1;
                count++;
                e.push_back(num[i]);
                if(count == max ) {
                    res.push_back(e);
                    e.pop_back();
                    count--;
                } else {
                    helper(num,check,res,e, count, max);
                    count--;
                    e.pop_back();
                }
            }
            
        }
    }
};


/*
 
 Solution s;
 
 vector<vector<int> > res = s.combine(4,3);
 
 for ( int i = 0; i < res.size(); i++) {
 for(int j = 0; j < res[i].size(); j++) {
 cout << res[i][j] << " ";
 }
 cout << endl;
 }
 
 */


#endif
