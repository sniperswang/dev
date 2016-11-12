//
//  maxProfit2.h
//  leetCode
//
//  Created by Yao Wang on 9/15/13.
//
//

#ifndef leetCode_maxProfit2_h
#define leetCode_maxProfit2_h

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(prices.size() < 2){
            return 0;
        }
        
        int profit = 0;;
        for(int i = 0; i < prices.size() -1; i++) {
            if(prices[i] < prices[i+1]) {
                profit += prices[i+1] - prices[i];
            }
        }
        
        return profit;
        
    }
};

/*
 vector<int> v;
 v.push_back(1);
 v.push_back(2);
 v.push_back(4);
 
 Solution s;
 int res= s.maxProfit(v);
 cout << res << endl;
 */

#endif
