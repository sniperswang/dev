//
//  lengthOfLastWord.h
//  leetCode
//
//  Created by Yao Wang on 9/29/13.
//
//

#ifndef leetCode_lengthOfLastWord_h
#define leetCode_lengthOfLastWord_h

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        
        string str(s);
        reverse(str.begin(),str.end());
        
        if(str.size() == 0)
            return 0;
        
        int pos = 0;
        while(str[pos] == ' ') {
            pos++;
            if(pos == str.length())
                break;
        }
        
        if(pos == str.length())
            return 0;
        
        
        while(str[pos] != ' '){
            pos++;
            len++;
            if(pos == str.length())
                break;
        }
        
        return len;
    }
};

/*
 const char *str = "hello world 123 ";
 Solution s;
 int len = s.lengthOfLastWord(str);
 cout << "len:" << len <<endl;
 */

#endif
