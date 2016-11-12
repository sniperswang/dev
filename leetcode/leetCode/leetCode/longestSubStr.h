//
//  longestSubStr.h
//  leetCode
//
//  Created by Yao Wang on 7/10/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef leetCode_longestSubStr_h
#define leetCode_longestSubStr_h

/*
 Longest Substring Without Repeating Characters
 Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

class Solution_sub {
public:
    int findSameCh(string s, char ch){
        int i = 0;
        
        while(i  < s.size() ){
            if(ch == s[i])
                return (i+1);
            else {
                i++;
            }
        }
        
        return 0;
        
    }
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(s.size() == 0)
            return 0;
        
        int posStr = 0;
        string s_substr="";
        s_substr+=s[0];
        int s_size = s.size(); // a integer size 
        int max_len = 1;
        int cur_len = 1;
        int i = 1;
        while(i < s_size ){
            char newCh = s[i];
            int ch_same_pos = findSameCh(s_substr,newCh);
            if (ch_same_pos == 0) {
                s_substr+=newCh;
                cur_len++;
                if(cur_len > max_len)
                    max_len = cur_len;
                i++;
            } else {
                if ( (s_size - (posStr + ch_same_pos)) <= max_len)
                    break;
                else {
                    posStr = posStr + ch_same_pos;
                    i = posStr + 1;
                    s_substr="";
                    s_substr+=s[posStr];
                    if(cur_len > max_len)
                        max_len = cur_len;
                    cur_len=1;
                }
            }
        }
        return max_len;
    }
};


#endif
