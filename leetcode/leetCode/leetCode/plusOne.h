//
//  plusOne.h
//  leetCode
//
//  Created by Yao Wang on 3/14/14.
//
//

#ifndef leetCode_plusOne_h
#define leetCode_plusOne_h

/*
 
 Given a non-negative number represented as an array of digits, plus one to the number.
 
 The digits are stored such that the most significant digit is at the head of the list.
 
 */


class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector <int> res(digits);
        std::reverse(res.begin(), res.end());
        vector<int>::iterator iter = res.begin();
        
        int nonZeroPos = 0;
        
        for(;iter != res.end(); iter++ ) {
            if(*iter != 9) {
                break;
            }
            nonZeroPos++;
        }
        
        if( nonZeroPos == res.size() ) {
            std::fill(res.begin(), res.end(), 0);
            res.push_back(1);
        } else {
            std::fill(res.begin(), res.begin()+nonZeroPos , 0);
            res[nonZeroPos]++;
        }
        std::reverse(res.begin(), res.end());
        
        return res;
    }
};

/*
 int my_ints [] = {9,8,9};
 vector<int> digits(my_ints,my_ints+3);
 
 Solution s;
 
 vector<int> res = s.plusOne(digits);
 
 vector<int>::iterator iter = res.begin();
 for(;iter != res.end(); iter++){
 cout << *iter << " ";
 }
 cout << endl;
 
 */

#endif
