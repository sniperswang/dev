//
//  mergeTwoLists.h
//  leetCode
//
//  Created by Yao Wang on 12/25/13.
//
//

#ifndef leetCode_mergeTwoLists_h
#define leetCode_mergeTwoLists_h


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode *next = NULL;
        ListNode *prev = NULL;
        
        ListNode *l1_pos = l1;
        ListNode *l2_pos = l2;
        
        if(l1 == NULL && l2 == NULL) {
            return head;
        }
        
        if(l2 == NULL && l1 != NULL) {
            head = l1;
            return head;
        }
        
        if(l1 == NULL && l2 != NULL) {
            head = l2;
            return head;
        }
        
        if(l1_pos->val < l2_pos->val) {
            head = l1_pos;
            l1_pos = l1_pos->next;
        } else {
            head = l2_pos;
            l2_pos = l2_pos->next;
        }
        
        prev = head;
        
        while(true) {
            
            if(l1_pos == NULL && l2_pos != NULL) {
                next = l2_pos;
                prev->next = next;
                prev = next;
                l2_pos = l2_pos->next;
                continue;
            }
            
            if(l2_pos == NULL && l1_pos != NULL) {
                next = l1_pos;
                prev->next = next;
                prev = next;
                l1_pos = l1_pos->next;
                continue;
            }
            
            if(l2_pos == NULL && l1_pos == NULL) {
                prev->next = NULL;
                break;
            }
            
            if(l1_pos->val < l2_pos->val) {
                next = l1_pos;
                l1_pos = l1_pos->next;
            }else{
                next = l2_pos;
                l2_pos = l2_pos->next;
            }
            
            prev->next = next;
            prev = next;
            
        }
        
        return head;
    }
};

/*
 ListNode a(-9);
 ListNode b1(5);
 ListNode b2(7);
 ListNode b3(3);
 
 b1.next = &b2;
 a.next = &b3;
 
 Solution s;
 ListNode *newList = s.mergeTwoLists(&a, &b1);
 
 ListNode *currNode = newList;
 
 while(currNode != NULL) {
 cout << currNode->val << " " ;
 currNode = currNode->next;
 }
 cout << endl;
 */


#endif
