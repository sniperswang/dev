//
//  flatten.h
//  leetCode
//
//  Created by Yao Wang on 1/18/14.
//
//

#ifndef leetCode_flatten_h
#define leetCode_flatten_h


/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        
        deque<TreeNode*> deq_Tnodes;
        
        if (root == NULL) {
            return;
        } else {
            retrieveNode(root, deq_Tnodes);
        }
        
        unsigned long long len = deq_Tnodes.size();
        
        TreeNode *prev = deq_Tnodes[0];
        TreeNode *curr = NULL;
        for (unsigned long long  i = 1; i < len; i++) {
            curr = deq_Tnodes[i];
            // reset
            prev->left  = NULL;
            prev->right = NULL;
            
            prev->right = curr;
            prev = curr;
        }
    }
    
    void retrieveNode(TreeNode *node, deque<TreeNode*> &deq_Tnodes) {
        
        if (node != NULL) {
            deq_Tnodes.push_back(node);
        } else {
            return;
        }
        
        if(node->left != NULL) {
            retrieveNode(node->left, deq_Tnodes);
        }
        
        if(node->right != NULL) {
            retrieveNode(node->right, deq_Tnodes);
        }
        
        return;
    }
    
};


#endif
