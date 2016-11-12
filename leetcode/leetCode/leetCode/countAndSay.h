//
//  countAndSay.h
//  leetCode
//
//  Created by Yao Wang on 4/9/14.
//
//

#ifndef leetCode_countAndSay_h
#define leetCode_countAndSay_h

class Solution {
public:
    string countAndSay(int n) {
        string res = "";
        
        if(n == 0) {
            return res;
        }
        
        res += '1';
        
        if (n == 1) {
            return res;
        }
        
        for (int i = 1; i < n; i++) {
            size_t size = res.size();
            string tmp="";
            char count = '1';
            for(int j = 0; j < size; j++) {
                if(j == size - 1) {
                    tmp += count;
                    tmp += res[j];
                } else {
                    if(res[j] == res[j+1]) {
                        count++;
                    } else {
                        tmp += count;
                        tmp += res[j];
                        if(count > '1') {
                            count = '1';
                        }
                    }
                    
                }
            }
            res = tmp;
        }
        
        return res;
    }
};

/*
 
 int n = 10;
 
 Solution s;
 
 string res = s.countAndSay(n);
 cout << "res:" << res << endl;
 
 */


#endif
