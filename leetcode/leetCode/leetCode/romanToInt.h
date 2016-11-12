//
//  romanToInt.h
//  leetCode
//
//  Created by Yao Wang on 3/2/14.
//
//

#ifndef leetCode_romanToInt_h
#define leetCode_romanToInt_h


class Solution {
public:
    int romanToInt(string s) {
        
        std::map<char, int> m_CharToInt;
        m_CharToInt['I'] = 1;
        m_CharToInt['V'] = 5;
        m_CharToInt['X'] = 10;
        m_CharToInt['L'] = 50;
        m_CharToInt['C'] = 100;
        m_CharToInt['D'] = 500;
        m_CharToInt['M'] = 1000;
        
        int val = 0;
        
        if (s.length() == 0) {
            return val;
        } else if (s.length() == 1) {
            val = m_CharToInt[s[0]];
            return val;
        }
        
        int preVal = m_CharToInt[s[s.length()-1]];
        int curVal = preVal;
        val = curVal;
        
        unsigned long long i = s.length() - 2;
        
        while (true) {
            curVal = m_CharToInt[s[i]];
            if(preVal > curVal ) {
                val = val - curVal;
            } else {
                val = val + curVal;
            }
            if( i == 0) {
                break;
            } else {
                i -- ;
            }
            preVal = curVal;
        }
        
        return val;
    }
};

/*
 
 string str = "D";
 
 Solution s;
 
 int val = s.romanToInt(str);
 
 cout << " val :" << val << endl;
 
 
 */

#endif
