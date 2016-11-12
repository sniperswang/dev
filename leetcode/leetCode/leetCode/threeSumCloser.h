//
//  threeSumCloser.h
//  leetCode
//
//  Created by Yao Wang on 8/31/13.
//
//

#ifndef leetCode_threeSumCloser_h
#define leetCode_threeSumCloser_h

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        sort(num.begin(),num.end());
        vector<vector<int> > res;
        
        
        if(num.size() < 3){
            return 0;
        }
        
        
        
        int res_val = abs(num[0]+num[1]+num[2] - target);
        int res_sum = num[0]+num[1]+num[2];
        
        for(int i = 0; i <= num.size()-3; i++) {
            int a = num[i];
            int k = i+1;
            int l = num.size() - 1;
            
            while(k < l) {
                int b = num[k];
                int c = num[l];
                int val = a+b+c ;
                
                int delta = abs(val - target);
                if( delta < res_val){
                    //cout << a << " " << b << " " << c  << " "<< << endl;
                    res_val = delta;
                    res_sum = val;
                    while(k<l && num[k] == num[k-1]) k++;
                    while(k<l && num[l] == num[l+1]) l--;
                    
                }
                
                if (val > target ){
                    l--;
                } else if (val < target) {
                    k++;
                } else {
                    return target;
                }
                
            }
            
            if(i < num.size()- 1)
            {
                while(num[i] == num[i+1])
                    i++;
            }
        }
        return res_sum;
        
        
    }
};


/*
 int myints[] = {0,1,2};
 std::vector<int> num (myints, myints + sizeof(myints) / sizeof(int) );
 Solution s;
 int  res = s.threeSumClosest(num,0);
 
 cout << "res :" << res << endl;
 
 */

#endif
