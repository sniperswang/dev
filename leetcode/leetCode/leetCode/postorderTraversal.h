//
//  postorderTraversal.h
//  leetCode
//
//  Created by Yao Wang on 11/28/13.
//
//

#ifndef leetCode_postorderTraversal_h
#define leetCode_postorderTraversal_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        
        deque <TreeNode *> d_queue;
        deque <TreeNode *> t_queue;
        
        d_queue.push_front(root);
        
        while(d_queue.size() !=0 ) {
            
            TreeNode *top = NULL;
            TreeNode *left = NULL;
            TreeNode *right = NULL;
            
            top = d_queue.front();
            
            if(t_queue.size() != 0) {
                TreeNode* t_top = t_queue.front();
                
                if(top == t_top) {
                    res.push_back(top->val);
                    d_queue.pop_front();
                    t_queue.pop_front();
                    continue;
                }
                
            }
            
            if(top->right != NULL) {
                right = top->right;
                d_queue.push_front(right);
            }
            
            if(top->left != NULL) {
                left = top->left;
                d_queue.push_front(left);
            }
            
            if (top->left  == NULL && top->right == NULL) {
                res.push_back(top->val);
                d_queue.pop_front();
            } else {
                t_queue.push_front(top);
            }
            
        } // while
        
        return res;
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
 
 vector<int> res;
 res = s.postorderTraversal(&a);
 
 for (int i = 0; i < res.size(); i ++) {
 cout << res[i] << " ";
 }
 cout << endl;
 
 */
 


#endif
