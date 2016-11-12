//
//  Permutations.h
//  leetCode
//
//  Created by Yao Wang on 9/13/13.
//
//

#ifndef leetCode_Permutations_h
#define leetCode_Permutations_h

/*
 
 Given a collection of numbers, return all possible permutations.
 
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 
 */

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        vector<int> check;
        for(int i = 0; i < num.size(); i++) {
            check.push_back(0);
        }
        int count = 0;
        vector<int> e;
        helper(num,check,res,e,count);
        return res;
        
    }
    
    void helper(vector<int> &num, vector<int> check, vector<vector<int> > &res, vector<int> e, int count) {
        
        for( int i = 0; i < check.size(); i++ ) {
            if(check[i] == 0) {
                check[i] = 1;
                count++;
                e.push_back(num[i]);
                if(count == num.size()) {
                    res.push_back(e);
                } else {
                    helper(num,check,res,e, count);
                    check[i] = 0;
                    count--;
                    e.pop_back();
                }
            }
            
        }
    }
    
    
};

/*
 
 int myints[4] = {1,2,3,4};
 std::vector<int> num (myints, myints + sizeof(myints) / sizeof(int) );
 Solution s;
 vector<vector<int> > res = s.permute(num);
 cout << "done :" << res.size() <<endl;

 
 */

#endif
