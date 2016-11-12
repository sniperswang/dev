//
//  grayCode.h
//  leetCode
//
//  Created by Yao Wang on 5/15/14.
//
//

#ifndef leetCode_grayCode_h
#define leetCode_grayCode_h

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        
        if ( n < 0 )
            return res;
        
        res.push_back(0);
        
        for(int i = 0; i < n; i++) {
            size_t len = res.size();
            int delta = 1<<i;
            for(int j = len -1; j >= 0 ; j--) {
                res.push_back(res[j] + delta);
            }
        }
        
        
        for (int i = 0; i < res.size();i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        
        return res;
    }
};

/*
 Solution s;
 
 s.grayCode(4);
 
 */

#endif
