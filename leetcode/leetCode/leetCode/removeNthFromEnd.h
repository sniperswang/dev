//
//  removeNthFromEnd.h
//  leetCode
//
//  Created by Yao Wang on 9/25/13.
//
//

#ifndef leetCode_removeNthFromEnd_h
#define leetCode_removeNthFromEnd_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int i = 1;
        
        ListNode* curr = head;
        while(i < n && curr != NULL) {
            curr = curr->next;
            i++;
        }
        
        if( i != n) {
            return head;
        }
        
        ListNode *pos = head;
        ListNode *prev = head;
        while(curr->next != NULL) {
            prev= pos;
            pos = pos->next;
            curr = curr->next;
        }
        
        if(pos == head) {
            return pos->next;
        } else {
            prev->next = pos->next;
            return head;
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
 ListNode* curr = s.removeNthFromEnd(&a,1);
 
 while( curr != NULL) {
 cout << curr->val << " ";
 curr = curr->next;
 }
 
 cout << endl;
 */


#endif
