//
//  sortedArrayToBST.h
//  leetCode
//
//  Created by Yao Wang on 4/13/14.
//
//

#ifndef leetCode_sortedArrayToBST_h
#define leetCode_sortedArrayToBST_h

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        
        TreeNode* root = NULL;
        
        if( num.size() == 0) {
            return root;
        }
        root = helper(num,0, num.size() - 1);
        return root;
        
    }
    
    TreeNode * helper(vector<int> num, size_t s, size_t e) {
        cout << "helper:" << num[ (s+e) / 2 ] << " s:" << s << " e:" << e << endl;
        TreeNode* root = NULL;
        if( s > e ) {
            return root;
        }
        
        if( s == e) {
            root = new TreeNode(num[s]);
            return root;
        }
        
        int val = num[ (s+e) / 2 ];
        root = new TreeNode(val);
        if( (s+e)/2 == 0) {
            root->left  = NULL;
        } else {
            root->left  = helper(num, s, ((s+e)/2) -1);
        }
        
        root->right = helper(num, ((s+e)/2) + 1, e);
        return root;
    }
};

/*
 
 void printTreeNode(TreeNode *node) {
 
 if( node->left == NULL && node->right == NULL ) {
 cout << " " << node->val << endl;
 return;
 }
 
 if(node->left != NULL) {
 printTreeNode(node->left);
 }
 
 cout << " " << node->val << endl;
 
 if(node->right != NULL) {
 printTreeNode(node->right);
 }
 
 return;
 
 }
 
 // int a [] = {1,2,3,4,5,6,7,8};
 
 int a [] = {1,3};
 
 vector<int> test(a,a+2);
 
 Solution s;
 
 TreeNode *node = s.sortedArrayToBST(test);
 
 printTreeNode(node);
 
 
 cout << "done" << endl;
 
 */

#endif
