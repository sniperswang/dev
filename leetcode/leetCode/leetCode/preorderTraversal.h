//
//  preorderTraversal.h
//  leetCode
//
//  Created by Yao Wang on 11/28/13.
//
//

#ifndef leetCode_preorderTraversal_h
#define leetCode_preorderTraversal_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        
        deque <TreeNode *> l_queue;
        deque <TreeNode *> r_queue;
        l_queue.push_front(root);
        
        while(l_queue.size() !=0 ) {
            
            TreeNode *top = NULL;
            TreeNode *left = NULL;
            TreeNode *right = NULL;
            
            top = l_queue.front();
            res.push_back(top->val);
            
            if(top->left != NULL) {
                left = top->left;
                l_queue.push_front(left);
            } if(top->right != NULL) {
                right = top->right;
                r_queue.push_front(right);
            }
            
            l_queue.pop_back();
            
            if ( l_queue.size() == 0) {
                if (r_queue.size() != 0) {
                    top = r_queue.front();
                    l_queue.push_front(top);
                    r_queue.pop_front();
                } else {
                    break; // left node queue and right node queue is both empty
                }
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
 res = s.preorderTraversal(&a);
 
 for (int i = 0; i < res.size(); i ++) {
 cout << res[i] << " ";
 }
 cout << endl;
 
 */


#endif
