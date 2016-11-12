//
//  validPalindrome.h
//  leetCode
//
//  Created by Yao Wang on 9/4/13.
//
//

#ifndef leetCode_validPalindrome_h
#define leetCode_validPalindrome_h


class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string strA = "";
        
        if (s.size() <= 1)
            return true;
        
        
        string::iterator iter = s.begin();
        for(;iter<s.end();iter++){
            if( int(*iter) >= int('a') && int(*iter) <=int('z') ){
                char x = (*iter);
                x = toupper(x);
                strA=strA+x;
            } else if( int(*iter) >= int('A') && int(*iter) <=int('Z') ){
                char x = (*iter);
                x = toupper(x);
                strA=strA+x;
            } else if ( int(*iter) >= int('0') && int(*iter) <=int('9')) {
                char x = (*iter);
                x = toupper(x);
                strA=strA+x;
            }
        }
        
        string strB = string (strA.rbegin(), strA.rend() );
        
        //  cout << "A: " << strA << endl;
        //  cout << "B: " << strB << endl;
        
        if (strB.compare(strA) != 0){
            return false;
        }else {
            return true;
        }
        
        
        return true;
    }
};

/*
 
 /*Valid Palindrome
 
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 
 For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome.
 
 Note:
 Have you consider that the string might be empty? This is a good question to ask during an interview.
 
 For the purpose of this problem, we define empty string as valid palindrome.
 
 */

 
 string str = "A man, a plan, a canal: Panama";
 
 Solution s;
 bool res = s.isPalindrome(str);
 
 cout << " res:" << res << endl;
 
 */


#endif
