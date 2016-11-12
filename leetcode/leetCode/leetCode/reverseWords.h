//
//  reverseWords.h
//  leetCode
//
//  Created by Yao Wang on 3/14/14.
//
//

#ifndef leetCode_reverseWords_h
#define leetCode_reverseWords_h

/*
 Given an input string, reverse the string word by word.
 
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 */

class Solution {
public:
    void reverseWords(string &s) {
        
        string s_save(s.c_str());
        char *str = const_cast<char *>(s_save.c_str());
        s.clear();
        char * pch;
        pch = strtok (str," ");
        vector<string> str_array;
        while (pch != NULL)
        {
            if(pch != NULL) {
                str_array.push_back(pch);
            }
            
            pch = strtok (NULL, " ");
            
        }
        vector<string>::reverse_iterator riter = str_array.rbegin();
        
        if( riter != str_array.rend() ) {
            s = s + *riter;
            riter++;
        }
        for(;riter != str_array.rend(); riter++) {
            s = s + " ";
            s = s + *riter;
        }
        
    }
};

/*
 
 //string str = "  a  b  c  ";
 string str = "the sky is blue";
 
 Solution s;
 
 s.reverseWords(str);
 
 
 */

#endif
