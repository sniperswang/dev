//
//  maxTreeDepth.h
//  leetCode
//
//  Created by Yao Wang on 9/21/13.
//
//

#ifndef leetCode_maxTreeDepth_h
#define leetCode_maxTreeDepth_h

// * Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(root == NULL){
            return 0;
        } else {
            int left_child_max_depth = maxDepth(root->left);
            int right_child_max_depth = maxDepth(root->right);
            
            int max = left_child_max_depth;
            if(left_child_max_depth < right_child_max_depth) {
                max = right_child_max_depth;
            }
            
            return (1+max);
        }
        
        return 0;
        
    }
    
};


#endif
