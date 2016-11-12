//
//  partition2.h
//  leetCode
//
//  Created by Yao Wang on 3/30/14.
//
//

#ifndef leetCode_partition2_h
#define leetCode_partition2_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) {
            return head;
        }
        
        ListNode *lessNode = NULL;
        ListNode *greatNode = NULL;
        ListNode *greatNodeStart = NULL;
        ListNode *lessNodestart = NULL;
        ListNode *node = head;
        
        while(node != NULL) {
            if(node->val < x) {
                if(lessNode == NULL) {
                    lessNode = node;
                    lessNodestart = node;
                } else {
                    lessNode->next = node;
                    lessNode = node;
                }
            } else {
                if( greatNode == NULL) {
                    greatNode = node;
                    greatNodeStart = node;
                } else {
                    greatNode->next = node;
                    greatNode = node;
                }
            }
            node = node->next;
        }
        
        if(lessNode == NULL) {
            return head;
        }
        
        if(greatNodeStart == NULL) {
            return head;
        }
        
        lessNode->next = greatNodeStart;
        greatNode->next = NULL;
        
        return lessNodestart;
    }
};

/*
 ListNode a(1);
 ListNode b(4);
 ListNode c(3);
 ListNode d(2);
 ListNode e(5);
 ListNode f(2);
 
 a.next = &b;
 b.next = &c;
 c.next = &d;
 d.next = &e;
 e.next = &f;
 
 ListNode *node;
 
 Solution s;
 
 node = s.partition(&a,3);
 
 while(node != NULL) {
 
 cout << " " << node->val;
 node = node->next;
 }
 cout << endl;
*/

#endif
