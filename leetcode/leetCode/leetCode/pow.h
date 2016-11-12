//
//  pow.h
//  leetCode
//
//  Created by Yao Wang on 9/14/13.
//
//

#ifndef leetCode_pow_h
#define leetCode_pow_h

/*
 class Solution {
 public:
 double pow(double x, int n) {
 // Start typing your C/C++ solution below
 // DO NOT write int main() function
 double temp = 0;
 // aviod 0;
 if (x == 0)
 return x;
 
 if ( n == 0)
 return 1;
 
 if( n > 0) {
 temp = x;
 while(n > 1) {
 temp = temp * x;
 n--;
 }
 } else {
 temp = 1/x;
 while( n < -1) {
 temp = temp * (1/x);
 }
 }
 return temp;
 }
 
 };
 */

// effiicient way

class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double temp = 0;
        // aviod 0;
        
        if ( n == 0)
            return 1;
        
        if (x == 0)
            return x;
        
        if ( n > 0) {
            temp = powHelper(x, (long long)n);
        } else {
            temp = 1 / ( powHelper(x, -(long long)n) ) ;
        }
        
        return temp;
    }
    
    double powHelper(double x, long long n) {
        
        int mod = n % 2;
        int div = n / 2;
        
        if(x == 0) {
            return 1;
        }
        
        if ( n == 0)
            return 1;
        
        if ( n == 1) {
            return x;
        }
        
        double divPart = powHelper(x, div);
        double modPart = powHelper(x, mod);
        
        return divPart * divPart * modPart;
    }
    
};

#endif
