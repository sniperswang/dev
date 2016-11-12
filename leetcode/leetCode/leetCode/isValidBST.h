//
//  isValidBST.h
//  leetCode
//
//  Created by Yao Wang on 4/5/14.
//
//

#ifndef leetCode_isValidBST_h
#define leetCode_isValidBST_h

class Solution {
public:
    
    bool isValidBST(TreeNode *root) {
        int prevVal = 0;
        bool minValueFound = false;
        if(root == NULL)
            return true;
        
        if(root->left == NULL) {
            prevVal = root->val;
            minValueFound = true;
            return helper(root->right, prevVal,minValueFound);
        }
        
        return helper(root, prevVal,minValueFound);
    }
    
    bool helper(TreeNode *node, int &prevVal, bool &minValueFound) {
        if(node == NULL) {
            return true;
        }
        
        if(node->right == NULL&& node->left == NULL) {
            
            if(!minValueFound) {
                minValueFound = true;
                prevVal = node->val;
                return true;
            }
            
            if(node->val <= prevVal) {
                return false;
            }else {
                prevVal = node->val;
                return true;
            }
        }
        
        if( !helper(node->left,prevVal,minValueFound) ) {
            return  false;
        }
        
        if(node->val <= prevVal) {
            return false;
        }else {
            prevVal = node->val;
        }
        
        
        if(!helper(node->right,prevVal,minValueFound) ) {
            return false;
        }
        
        return true;
    }
    
    
};

#endif
