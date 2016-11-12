//
//  palindromeNumber.h
//  leetCode
//
//  Created by Yao Wang on 8/24/13.
//
//

#ifndef leetCode_palindromeNumber_h
#define leetCode_palindromeNumber_h

class Solution { // 08/24
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(x < 0 )
            return false;
        if(x < 10)
            return true;
        
        int div = 1;
        int temp = x;
        int len = 0;
        while(temp >= 10) { // overflow for div
            div = div * 10;
            len++;
            temp = temp / 10;
        }
        
        len++;
        int start= 1;
        int end = len;
        div = div / 10;
        
        while(start < end){
            int r = x % 10;
            int l = x / div / 10;
            
            if ( r != l ){
                return false;
            }
            x = (x % (div*10) ) / 10 ;
            div = (div / 100);
            start++;
            end--;
        }
        
        return true;
        
    }
};

/*
 Solution s;
 int i = 11;
 int res = s.isPalindrome(i);
 cout <<" res " << res <<"\n";
 */

#endif
