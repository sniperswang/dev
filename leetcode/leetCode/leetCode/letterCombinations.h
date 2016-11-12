//
//  letterCombinations.h
//  leetCode
//
//  Created by Yao Wang on 9/1/14.
//
//

#ifndef leetCode_letterCombinations_h
#define leetCode_letterCombinations_h

class Solution
{
private:
    map<char, string> dig2char;
    
public:
    Solution()
    {
        dig2char['2'] = "abc";
        dig2char['3'] = "def";
        dig2char['4'] = "ghi";
        dig2char['5'] = "jkl";
        dig2char['6'] = "mno";
        dig2char['7'] = "pqrs";
        dig2char['8'] = "tuv";
        dig2char['9'] = "wxyz";
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        result.push_back("");
        
        for (int i = 0; i < digits.size(); ++i)
        {
            vector<string> tmp;
            for (int j = 0; j < dig2char[digits[i]].size(); ++j)
            {
                for (int k = 0; k < result.size(); ++k)
                {
                    cout << "result[" << k <<"]:" << result[k] << endl;
                    string __str = result[k] + dig2char[digits[i]][j];
                    cout << "__str:" << __str << endl;
                    tmp.push_back(__str);
                }
            }
            result = tmp;
        }
        return result;
    }
};

/*
 
 test case 
 
 string str = "234";
 
 vector<string> res;
 
 Solution s;
 
 res = s.letterCombinations(str);
 
 for(int i = 0; i < res.size(); i++)
 {
 cout << "," << res[i];
 }
 cout << endl;
 
 */

#endif
