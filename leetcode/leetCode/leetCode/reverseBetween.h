//
//  reverseBetween.h
//  leetCode
//
//  Created by Yao Wang on 3/29/14.
//
//

#ifndef leetCode_reverseBetween_h
#define leetCode_reverseBetween_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *res;
        if ( head == NULL) {
            return head;
        }
        
        ListNode  *node  = head;
        ListNode  *start = NULL;
        ListNode  *end   = NULL;
        ListNode  *start_prev = head;
        ListNode  *end_next   = NULL;
        
        int index = 1;
        while (index < m) {
            start_prev = node;
            node = node->next;
            if (node == NULL){
                // this sould not happen
                break;
            }
            index++;
        }
        
        start = node;
        while(index < n) {
            node = node->next;
            if (node == NULL){
                // this sould not happen
                break;
            }
            index++;
        }
        end = node;
        end_next=node->next;
        
        node = start;
        //   cout << "start:" << start->val <<endl;
        //    cout << "end:" << end->val <<endl;
        
        ListNode *node_prev = NULL;
        while(node != end_next){
            ListNode *savNextNode = node->next;
            if(node != start){
                //       cout << "node:" << node->val <<endl;
                node->next = node_prev;
            }
            node_prev = node;
            node = savNextNode;
        }
        
        if(m > 1) {
            start_prev->next = end;
        } else {
            head = end;
        }
        
        start->next = end_next;
        
        if(m == 1){
            res = end;
        }else {
            res = head;
        }
        
        return res;
    }
};


/*
 
 ListNode a(1);
 ListNode b(2);
 ListNode c(3);
 ListNode d(4);
 ListNode e(5);
 
 a.next = &b;
 b.next = &c;
 c.next = &d;
 d.next = &e;
 
 ListNode *node;
 
 Solution s;
 
 node = s.reverseBetween(&a,1,5);
 
 while(node != NULL) {
 
 cout << " " << node->val;
 node = node->next;
 }
 cout << endl;
 
 */

#endif
