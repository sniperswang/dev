//
//  combinationSum.h
//  leetCode
//
//  Created by Yao Wang on 3/27/14.
//
//

#ifndef leetCode_combinationSum_h
#define leetCode_combinationSum_h

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        if(candidates.size() == 0) {
            return res;
        }
        std::sort(candidates.begin(),candidates.begin()+candidates.size());
        vector<int> e;
        helper(candidates, res, e, target,0);
        return res;
    }
    
    void helper(vector<int> &candidates, vector<vector<int> > &res, vector<int> &e,int target, int pos){
        
        if(target == 0){
            res.push_back(e);
            return ;
        }
        
        if( target < 0) {
            return;
        }
        
        int  len = candidates.size();
        
        for(int i = pos; i < len; i++) {
            if ( candidates[i] <= target ) {
                e.push_back(candidates[i]);
                helper(candidates,res,e,(target-candidates[i]),i);
                e.pop_back();
            }else{
                return;
            }
        }
        
    }
    
};

#endif
