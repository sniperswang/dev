//
//  intToRoman.h
//  leetCode
//
//  Created by Yao Wang on 3/5/14.
//
//

#ifndef leetCode_intToRoman_h
#define leetCode_intToRoman_h

/*
 
 
 Given an integer, convert it to a roman numeral.
 
 Input is guaranteed to be within the range from 1 to 3999.
 
 
 */


class Solution {
public:
    string intToRoman(int num) {
        
        vector<int> numArray;
        numArray.push_back(1);
        numArray.push_back(4);
        numArray.push_back(5);
        numArray.push_back(9);
        numArray.push_back(10);
        numArray.push_back(40);
        numArray.push_back(50);
        numArray.push_back(90);
        numArray.push_back(100);
        numArray.push_back(400);
        numArray.push_back(500);
        numArray.push_back(900);
        numArray.push_back(1000);
        
        vector<string> strArray;
        strArray.push_back("I");  // 1
        strArray.push_back("IV"); // 4
        strArray.push_back("V");  // 5
        strArray.push_back("IX"); // 9
        strArray.push_back("X");  // 10
        strArray.push_back("XL"); // 40
        strArray.push_back("L");  // 50
        strArray.push_back("XC"); // 90
        strArray.push_back("C");  // 100
        strArray.push_back("CD"); // 400
        strArray.push_back("D");  // 500
        strArray.push_back("CM"); // 900
        strArray.push_back("M");  // 1000
        
        //int rest = num;
        int val = num;
        
        string res = "";
        unsigned long long index = numArray.size() - 1;
        
        while(val != 0) {
            if(val - numArray[index] >= 0) {
                res += strArray[index];
                val = val - numArray[index];
            } else {
                index--;
            }
        }
        
        return res;
    }
};

/*
 int num = 2014;
 
 Solution s;
 
 string res = s.intToRoman(num);
 
 cout << "res:" << res << endl;
 
 */

#endif
