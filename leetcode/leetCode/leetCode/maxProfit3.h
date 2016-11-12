//
//  maxProfit3.h
//  leetCode
//
//  Created by Yao Wang on 9/15/13.
//
//

#ifndef leetCode_maxProfit3_h
#define leetCode_maxProfit3_h


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size() < 2){
            return 0;
        }
        
        vector<int> leftMax(prices.size(), 0);
        int max = 0;
        unsigned long minIndex = 0;
        
        for(unsigned long i = 1; i < prices.size() ; i++) {
            if(prices[i] < prices[minIndex]){
                minIndex = i;
                leftMax[i] = leftMax[i-1];
            } else {
                int delta = prices[i] - prices[minIndex];
                if (delta > max){
                    max = delta;
                    leftMax[i]=max;
                }else{
                    leftMax[i] = leftMax[i-1];
                }
                
            }
            
        }
        
        vector<int> rightMax(prices.size(), 0);
        
        max=0;
        unsigned long maxIndex = prices.size() - 1;
        
        for(unsigned long i = prices.size() - 2; ; i--) {
            
            if(prices[i] > prices[maxIndex]) {
                maxIndex = i;
                rightMax[i] = rightMax[i+1];
            } else {
                int delta = prices[maxIndex] - prices[i];
                if(delta > max) {
                    max = delta;
                    rightMax[i] = max;
                }else{
                    rightMax[i] = rightMax[i+1];
                }
            }
            
            if( i == 0) {
                break;
            }
        }
        
        int max_total= leftMax[0]+rightMax[0];
        
        for(unsigned long i = 1; i < prices.size(); i++ ) {
            int local_max = leftMax[i]+rightMax[i];
            
            if( local_max > max_total )
                max_total = local_max;
        }
        
        return max_total;
        
    }
};



#endif
