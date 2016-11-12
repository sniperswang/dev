//
//  getPermutation.h
//  leetCode
//
//  Created by Yao Wang on 10/19/13.
//
//

#ifndef leetCode_getPermutation_h
#define leetCode_getPermutation_h

//Permutation Sequence

class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> factor;
        vector<int> nums;
        string res="";
        int val = 1;
        int divPart = 1;
        int modPart = 1;
        for(int i = 1; i < n; i++) {
            val = val * i;
            factor.push_back(val);
        }
        
        for(int  i = 1; i < n+1; i ++) {
            nums.push_back(i);
        }
        
        int kk = k - 1;
        
        for(int i =  1; i < n; i++){
            
            divPart = kk / factor[n - i - 1];
            modPart = kk % factor[n - i - 1];
            int digit = nums[divPart];
            kk = modPart;
            shiftArray(nums, divPart);
            char e[1];
            sprintf(e,"%d",digit);
            res=res+e;
        }
        char e;
        sprintf(&e,"%d",nums[0]);
        res=res+e;
        return res;
    }
    
    void shiftArray(vector<int> &v, int pos) {
        for(int i = pos; i < v.size() - 1; i++) {
            v[i] = v[i+1];
        }
    }
};

/*
 
 Solution s;
 
 string ss = s.getPermutation(4, 24);
 cout << "ss:" << ss <<endl;
 
 */


#endif
