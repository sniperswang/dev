//
//  subsets2.h
//  leetCode
//
//  Created by Yao Wang on 9/15/13.
//
//

#ifndef leetCode_subsets2_h
#define leetCode_subsets2_h

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(),S.end());
        vector<vector<int> > res;
        vector<int> check;
        for(int i = 0; i < S.size(); i++) {
            check.push_back(0);
        }
        int count = 0;
        vector<int> e;
        helper(S,check,res,e,0);
        res.push_back(e);
        return res;
        
    }
    
    
    void helper(vector<int> &num, vector<int> check, vector<vector<int> > &res, vector<int> e, int start ) {
        
        set<int> mark;
        for( int i = start; i < check.size(); i++ ) {
            if(check[i] == 0 && mark.find(num[i]) == mark.end() ){
                check[i] = 1;
                e.push_back(num[i]);
                if(start == num.size()) {
                    res.push_back(e);
                    return;
                } else {
                    res.push_back(e);
                    helper(num,check,res,e, i+1);
                    e.pop_back();
                    mark.insert(num[i]);
                }
            }
            
        }
    }
};

/*
 
 int myints[3] = {1,2,2};
 std::vector<int> num (myints, myints + sizeof(myints) / sizeof(int) );
 Solution s;
 vector<vector<int> > res = s.subsetsWithDup(num);
 
 for(int i = 0; i < res.size(); i++){
 for(int j = 0; j < res[i].size();j++){
 cout<<res[i][j];
 }
 cout<<endl;
 }
 cout << "done :" << res.size() <<endl;

 
 */
#endif
