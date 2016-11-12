//
//  minDepth.h
//  leetCode
//
//  Created by Yao Wang on 9/21/13.
//
//

#ifndef leetCode_minDepth_h
#define leetCode_minDepth_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return 0;
        int minDepth = -1;
        minDepth = minHelper(root, 1, minDepth);
        return minDepth;
    }
    
    int minHelper(TreeNode *root, int currDepth, int& minDepth) {
        if( root->left == NULL && root->right == NULL) {
            if (currDepth < minDepth || minDepth == -1) {
                minDepth = currDepth;
            }
            
            return minDepth;
        }
        
        //minDepth ++;
        if (root->left == NULL && root->right != NULL ) {
            return minHelper(root->right, currDepth+1, minDepth);
        } else if (root->left != NULL && root->right == NULL ) {
            return minHelper(root->left, currDepth+1, minDepth);
        }
        
        
        int leftMin  = minHelper(root->left, currDepth+1, minDepth);
        int rightMin = minHelper(root->right, currDepth+1, minDepth);
        
        if(leftMin < rightMin) {
            return leftMin;
        }else{
            return rightMin;
        }
    }
};

/*
 
 TreeNode a(1);
 TreeNode b(2);
 
 a.right=&b;
 
 Solution s;
 int len = s.minDepth(&a);
 
 */


#endif
