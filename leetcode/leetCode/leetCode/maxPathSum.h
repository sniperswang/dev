//
//  maxPathSum.h
//  leetCode
//
//  Created by Yao Wang on 9/21/13.
//
//

#ifndef leetCode_maxPathSum_h
#define leetCode_maxPathSum_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL ){
            return 0;
        }
        
        int max = root->val;
        helper(root,max);
        return max;
    }
    
    int maxArray(vector<int>& array, int size) {
        int max = array[0];
        for(int i = 0; i < size; i++){
            if(array[i] > max)
                max = array[i];
        }
        
        return max;
    }
    
    
    int helper(TreeNode *root, int &maxSum){
        
        if (root == NULL) {
            return 0;
        }
        
        int nodeVal = root->val;
        int Right = helper(root->right, maxSum);
        int Left  = helper(root->left,  maxSum);
        
        vector<int> v;
        
        v.push_back(nodeVal);
        v.push_back(nodeVal+Right);
        v.push_back(nodeVal+Left);
        v.push_back(nodeVal+Left+Right);
        
        int maxSub = maxArray(v, v.size());
        
        if(maxSub > maxSum) {
            maxSum = maxSub;
        }
        
        int maxNode = maxArray(v, v.size() -1);
        
        return maxNode;
    }
};

/*
 TreeNode a(0);
 TreeNode b(2);
 TreeNode c(3);
 TreeNode c_l(4);
 TreeNode c_r(5);
 
 a.right=&b;
 a.left=&c;
 c.right = &c_r;
 c.left  = &c_l;
 Solution s;
 int max = s.maxPathSum(&a);
 
 cout << "max:" << max << endl;
 */

#endif
