//
//  maxProfit.h
//  leetCode
//
//  Created by Yao Wang on 9/14/13.
//
//

#ifndef leetCode_maxProfit_h
#define leetCode_maxProfit_h

/*
 class Solution {
 public:
 int maxProfit(vector<int> &prices) {
 // Start typing your C/C++ solution below
 // DO NOT write int main() function
 
 if(prices.size() < 2){
 return 0;
 }
 
 int max = 0;
 
 for(int i = 0; i < prices.size()-1; i++) {
 int local_max = 0;
 
 for(int j = i + 1; j < prices.size(); j++ ) {
 int delta = prices[j] - prices[i];
 if(delta > local_max)
 local_max = delta;
 }
 
 if(local_max > max)
 max = local_max;
 }
 
 return max;
 
 
 }
 };
 */

//efficient way

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(prices.size() < 2){
            return 0;
        }
        
        int max = 0;
        
        int minIndex = 0;
        for(int i = 1; i < prices.size() ; i++) {
            if(prices[i] < prices[minIndex]){
                minIndex = i;
            } else {
                int delta = prices[i] - prices[minIndex];
                if (delta > max)
                    max = delta;
            }
            
        }
        
        return max;
        
    }
};

#endif
