//
//  Permutations_2.h
//  leetCode
//
//  Created by Yao Wang on 9/13/13.
//
//

#ifndef leetCode_Permutations_2_h
#define leetCode_Permutations_2_h

/*
 
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 
 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].
 
 */


class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
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
        
        set<int> mark;
        for( int i = 0; i < check.size(); i++ ) {
            if(check[i] == 0 && mark.find(num[i]) == mark.end() ) {
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
                    mark.insert(num[i]);
                }
            }
            
        }
    }
};

#endif
