//
//  anagrams.h
//  leetCode
//
//  Created by Yao Wang on 9/13/13.
//
//

#ifndef leetCode_anagrams_h
#define leetCode_anagrams_h

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        map<string, int> count;
        map<string,string> preStr;
        
        for(int i=0; i< strs.size(); i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(preStr.find(s) == preStr.end()){
                preStr[s] = strs[i];
                count[s] = 1;
            } else {
                if(count[s] == 1) {
                    res.push_back(preStr[s]);
                }
                count[s] = count[s] + 1;
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};

#endif
