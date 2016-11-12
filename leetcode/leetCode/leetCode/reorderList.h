//
//  reorderList.h
//  leetCode
//
//  Created by Yao Wang on 1/18/14.
//
//

#ifndef leetCode_reorderList_h
#define leetCode_reorderList_h

/*
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
    void reorderList(ListNode *head) {
        
        deque <ListNode *> deq_ptrs;
        
        if (head == NULL) {
            return;
        }
        ListNode *curr = head;
        while ( curr != NULL) {
            deq_ptrs.push_back(curr);
            curr = curr->next;
        }
        
        unsigned long long  len = deq_ptrs.size();
        
        if (len <= 2) {
            return;
        }
        
        for (unsigned long long i = 0; i < len; i++) {
            
            if( i >= len - i - 1 ) {
                deq_ptrs[i]->next = NULL;
                break;
            } else {
                deq_ptrs[i]->next = deq_ptrs[len -1-i];
                deq_ptrs[len -1-i]->next = deq_ptrs[i+1];
            }
            
        }
    }
};

/*
 ListNode a(1);
 ListNode b(2);
 ListNode c(3);
 
 a.next = &b;
 b.next = &c;
 
 Solution s;
 
 s.reorderList(&a);
 
 ListNode *curr = &a;
 
 while (curr != NULL) {
 cout << curr->val << " ";
 curr = curr->next;
 }
 cout << endl;
 */


#endif
