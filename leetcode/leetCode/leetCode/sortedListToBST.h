//
//  sortedListToBST.h
//  leetCode
//
//  Created by Yao Wang on 5/15/14.
//
//

#ifndef leetCode_sortedListToBST_h
#define leetCode_sortedListToBST_h

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode *sortedListToBST(ListNode *head) {
        
        TreeNode* root = NULL;
        
        if(head == NULL) {
            return root;
        }
        
        
        ListNode *node  = head;
        ListNode *start = head;
        ListNode *end   = head;
        
        while(node->next != NULL) {
            node = node->next;
        }
        
        end = node;
        
        if(start == end) {
            root = new TreeNode(head->val);
            return root;
        }
        
        root = helper(head, end);
        
        return root;
    }
    
    
    TreeNode* helper(ListNode *startNode, ListNode* endNode) {
        TreeNode* root = NULL;
        
        if(startNode == NULL || endNode == NULL) {
            return root;
        }
        
        if(startNode == endNode) {
            root = new TreeNode(startNode->val);
            return root;
        }
        
        // get mid node;
        ListNode* oneStepNode = startNode;
        ListNode* twoStepNode = startNode;
        ListNode* oneStepNodePrev = startNode;
        
        int count  = 0;
        while(twoStepNode != endNode && twoStepNode != NULL) {
            twoStepNode = twoStepNode->next;
            count++;
            if(count == 2) {
                oneStepNodePrev = oneStepNode;
                oneStepNode = oneStepNode ->next;
                count = 0;
            }
        }
        
        // No change
        if(oneStepNode == startNode) {
            root = new TreeNode(startNode->val);
            root->right = helper(oneStepNode->next, endNode);
            return root;
        }
        
        root = new TreeNode ( oneStepNode->val );
        root->left  = helper(startNode, oneStepNodePrev);
        root->right = helper(oneStepNode->next, endNode);
        
        return root;
    }
    
    
};


void printTreeNode(TreeNode *node) {
    
    if(node == NULL) {
        return;
    }
    
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

/*
 
 cout << "hello" << endl;
 ListNode a(1);
 ListNode b(2);
 ListNode c(3);
 ListNode d(4);
 ListNode e(5);
 ListNode f(6);
 ListNode g(7);
 
 a.next = &b;
 b.next = &c;
 c.next = &d;
 d.next = &e;
 e.next = &f;
 f.next = &g;
 
 Solution s;
 
 TreeNode *node = s.sortedListToBST(&a);
 printTreeNode(node);
 
 */

#endif
