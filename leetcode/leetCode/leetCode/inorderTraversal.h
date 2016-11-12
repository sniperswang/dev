//
//  inorderTraversal.h
//  leetCode
//
//  Created by Yao Wang on 9/25/13.
//
//

#ifndef leetCode_inorderTraversal_h
#define leetCode_inorderTraversal_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode*> qt;
        vector<int> vec;
        
        if (root == NULL) {
            return vec;
        }
        
        helper(root,vec);
        return vec;
    }
    
    void helper(TreeNode* root, vector<int>& vec) {
        if(root->left == NULL && root->right == NULL) {
            vec.push_back(root->val);
            return;
        }
        
        if(root->left != NULL) {
            helper(root->left,vec);
        }
        
        vec.push_back(root->val);
        
        if(root->right != NULL) {
            helper(root->right,vec);
        }
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
 
 vector<int> v = s.inorderTraversal(&a);
 
 for(int i = 0; i < v.size(); i++){
 cout << v[i] << " ";
 cout << endl;
 }
 
 */

#endif
