//
//  combinationSum2.h
//  leetCode
//
//  Created by Yao Wang on 3/27/14.
//
//

#ifndef leetCode_combinationSum2_h
#define leetCode_combinationSum2_h


class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        if(num.size() == 0) {
            return res;
        }
        
        std::sort(num.begin(),num.begin()+num.size());
        
        vector<int> e;
        helper(num, res, e, target,0);
        return res;
        
    }
    
    void helper(vector<int> &num, vector<vector<int> > &res, vector<int> &e,int target, int pos){
        
        if(target == 0){
            // print(e);
            res.push_back(e);
            return ;
        }
        
        if( target < 0) {
            return;
        }
        
        int  len = num.size();
        set<int> i_set;
        for(int i = pos; i < len; i++) {
            if ( num[i] <= target ) {
                if(i_set.find(num[i]) == i_set.end()){
                    i_set.insert(num[i]);
                }else {
                    continue;
                }
                e.push_back(num[i]);
                helper(num,res,e,(target-num[i]),i+1);
                e.pop_back();
            }else{
                return;
            }
        }
        
    }
    
};

#endif
