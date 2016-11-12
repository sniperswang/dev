//
//  sumPathNum.h
//  leetCode
//
//  Created by Yao Wang on 9/21/13.
//
//

#ifndef leetCode_sumPathNum_h
#define leetCode_sumPathNum_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return 0;
        }
        
        vector<int> v;
        helper(root,0,v);
        int val = sum(v);
        return val;
        
    }
    
    int sum (vector<int> &v) {
        int sum = 0;
        for(int i =0; i < v.size(); i++ ){
            sum += v[i];
        }
        return sum;
    }
    
    void helper(TreeNode *root, int num, vector<int> & v){
        
        num = num*10 + root->val;
        
        if( root->left == NULL && root->right == NULL) {
            v.push_back(num);
            return;
        }
        
        if (root->left == NULL && root->right != NULL ) {
            helper(root->right, num, v);
            return;
        } else if (root->left != NULL && root->right == NULL ) {
            helper(root->left,  num, v);
            return;
        }
        
        helper(root->right, num, v);
        helper(root->left,  num, v);
    }
};

/*
 
 TreeNode a(1);
 TreeNode b(2);
 TreeNode c(3);
 TreeNode c_l(4);
 TreeNode c_r(5);
 
 a.right=&b;
 a.left=&c;
 c.right = &c_r;
 c.left  = &c_l;
 Solution s;
 int sum = s.sumNumbers(&a);
 
 cout << "sum:" << sum  <<endl;
 /*
 
 */

#endif
