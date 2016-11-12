//
//  addTwoNumbers.h
//  leetCode
//
//  Created by Yao Wang on 2/18/14.
//
//

#ifndef leetCode_addTwoNumbers_h
#define leetCode_addTwoNumbers_h

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL && l2== NULL) {
            return NULL;
        }
        
        if(l1 == NULL && l2 != NULL) {
            return l2;
        }
        
        if(l1 != NULL && l2 == NULL) {
            return l1;
        }
        
        ListNode *curr = NULL;
        ListNode *prev = NULL;
        ListNode *head;
        int extra = 0;
        
        ListNode *l1_curr = l1;
        ListNode *l2_curr = l2;
        
        while(true) {
            
            int val = 0;
            
            if (l1_curr == NULL && l2_curr == NULL) {
                val = 0;
                if(extra == 0) {
                    break;
                }
            } else if ( l1_curr == NULL && l2_curr != NULL) {
                val = l2_curr->val;
            } else if ( l1_curr != NULL && l2_curr == NULL) {
                val = l1_curr->val;
            } else {
                val = l1_curr->val + l2_curr->val;
            }
            
            curr = new ListNode( (val + extra)  % 10 );
            
            if(prev != NULL) {
                prev->next = curr;
                prev = curr;
            } else {
                head = curr;
                prev = curr;
            }
            
            if ( val + extra >= 10) {
                extra = 1;
            } else {
                extra = 0;
            }
            
            if(l1_curr != NULL)
                l1_curr = l1_curr->next;
            
            if(l2_curr != NULL)
                l2_curr = l2_curr->next;
        }
        
        return head;
    }
};

/*
 ListNode a1(1);
 // ListNode b1(4);
 // ListNode c1(3);
 
 // a1.next = &b1;
 // b1.next = &c1;
 
 ListNode a2(9);
 ListNode b2(9);
 // ListNode c2(4);
 
 a2.next = &b2;
 //b2.next = &c2;
 
 
 Solution s;
 
 
 ListNode *node = s.addTwoNumbers(&a1, &a2);
 
 while(node != NULL) {
 cout << " " << node->val;
 node = node->next;
 }
 cout << endl;
 */

#endif
