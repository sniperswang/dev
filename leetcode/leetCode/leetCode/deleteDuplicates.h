//
//  deleteDuplicates.h
//  leetCode
//
//  Created by Yao Wang on 9/25/13.
//
//

#ifndef leetCode_deleteDuplicates_h
#define leetCode_deleteDuplicates_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(head == NULL)
            return head;
        
        ListNode *curr = head->next;
        ListNode *mark = head;
        while(curr != NULL) {
            if(curr->val != mark->val) {
                mark->next = curr;
                mark = curr;
            } else {
                curr = curr->next;
            }
        }
        
        mark->next=curr; // if a->b->c->1->1
        return head;
    }
};

/*
 
 ListNode a(1);
 ListNode b(1);
 ListNode c(1);
 
 a.next = &b;
 b.next = &c;
 
 Solution s;
 ListNode* curr = s.deleteDuplicates(&a);
 
 while( curr != NULL) {
 cout << curr->val << " ";
 curr = curr->next;
 }
 
 cout << endl;
 
 */


#endif
