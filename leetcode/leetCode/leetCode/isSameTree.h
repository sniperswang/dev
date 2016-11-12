//
//  isSameTree.h
//  leetCode
//
//  Created by Yao Wang on 9/21/13.
//
//

#ifndef leetCode_isSameTree_h
#define leetCode_isSameTree_h

// * Definition for binary tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        bool isSameNode  = false;
        bool isSameRight = false;
        bool isSameLeft  = false;
        
        if( (p== NULL && q == NULL) ) {
            return true;
        } else {
            if (p != NULL && q != NULL ) {
            } else {
                return false;
            }
        }
        
        if(p->val == q->val) {
            isSameNode = true;
        }else {
            return false;
        }
        
        
        if(p->right != NULL && q->right != NULL){
            isSameRight = isSameTree(p->right, q->right);
        } else {
            if(p->right == NULL && q->right == NULL)
                isSameRight = true;
            else
                return false;
        }
        
        if(p->left != NULL && q->left != NULL){
            isSameLeft = isSameTree(p->left, q->left);
        } else {
            if(p->left == NULL && q->left == NULL)
                isSameLeft = true;
            else
                return false;
        }
        
        return (isSameNode&&isSameRight&&isSameLeft);
    }
};

/*
 
 TreeNode *p = NULL;
 TreeNode q(0);
 
 Solution s;
 bool isSame = s.isSameTree(p,&q);
 
 cout << "isSame:" << isSame << endl;
 
 */

#endif
