//
//  generateParenthesis.h
//  leetCode
//
//  Created by Yao Wang on 3/26/14.
//
//

#ifndef leetCode_generateParenthesis_h
#define leetCode_generateParenthesis_h


/*
 class Solution {
 public:
 vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
 
 }
 };
 
 
 */



/*
 
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 
 For example, given n = 3, a solution set is:
 
 "((()))", "(()())", "(())()", "()(())", "()()()"
 */


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str(n*2, ' ');
        if(n == 0) {
            return res;
        }
        
        generateHelper(res,str,n,0,0,0);
        return res;
    }
    
    void generateHelper(vector<string> &res, string &str, int n, int open, int close, int pos) {
        if(close == n) {
            cout<<str<<endl;
            res.push_back(str);
            return;
        }
        
        if(open > close){
            str[pos] = ')';
            generateHelper(res,str,n,open,close+1,pos+1);
        }
        
        if(open < n) {
            str[pos] = '(';
            generateHelper(res,str,n,open+1,close,pos+1);
        }
        
    }
};

/*
 
 int n = 3;
 Solution s;
 vector<string> res;
 res = s.generateParenthesis(3);

 */

#endif
