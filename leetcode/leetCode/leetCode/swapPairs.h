//
//  swapPairs.h
//  leetCode
//
//  Created by Yao Wang on 2/18/14.
//
//

#ifndef leetCode_swapPairs_h
#define leetCode_swapPairs_h

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
    ListNode *swapPairs(ListNode *head) {
        
        if(head == NULL) {
            return head;
        }
        
        if(head->next == NULL) {
            return head;
        }
        
        ListNode *curr = head;
        ListNode *next = curr->next;
        ListNode *prev = NULL;
        
        curr->next = next->next;
        next->next = curr;
        
        prev = curr;
        curr = curr->next;
        head = next;
        
        while(curr != NULL && curr->next != NULL ) {
            next = curr->next;
            curr->next = next->next;
            next->next = curr;
            prev->next = next;
            prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};

/*
 
 ListNode a(1);
 ListNode b(2);
 ListNode c(3);
 ListNode d(4);
 
 a.next = &b;
 b.next = &c;
 //  c.next = &d;
 
 ListNode *node = &a;
 
 Solution s;
 
 node = s.swapPairs(&a);
 
 while( node != NULL) {
 cout << " " << node->val;
 node = node->next;
 }
 cout << endl;
 
 */

#endif
