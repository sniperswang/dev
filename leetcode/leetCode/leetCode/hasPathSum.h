//
//  hasPathSum.h
//  leetCode
//
//  Created by Yao Wang on 9/23/13.
//
//

#ifndef leetCode_hasPathSum_h
#define leetCode_hasPathSum_h

// * Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (root == NULL) {
            return false;
        }
        
        if(root->left == NULL && root->right == NULL) {
            if( root->val == sum){
                return true;
            }else{
                return false;
            }
        }
        
        bool val = helper(root, sum, 0);
        return val;
        
    }
    
    bool helper(TreeNode *root, int& sum, int currSum){
        if(root->left == NULL && root->right == NULL) {
            if( (currSum + root->val) == sum){
                return true;
            }else{
                return false;
            }
        }
        
        bool rightMatch  = false;
        bool leftMatch   = false;
        
        if(root->left == NULL && root->right != NULL) {
            rightMatch = helper(root->right, sum, currSum+root->val);
            return rightMatch;
        }
        
        if (root->left != NULL && root->right == NULL) {
            leftMatch = helper(root->left, sum, currSum+root->val);
            return leftMatch;
        }
        
        rightMatch = helper(root->right, sum, currSum+root->val);
        if(rightMatch)
            return true;
        
        leftMatch =  leftMatch = helper(root->left, sum, currSum+root->val);
        
        if (leftMatch)
            return true;
        
        return false;
        
    }
};

#endif
