//
//  insertionSortList.h
//  leetCode
//
//  Created by Yao Wang on 1/7/14.
//
//

#ifndef leetCode_insertionSortList_h
#define leetCode_insertionSortList_h


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
    ListNode *insertionSortList(ListNode *head) {
        
        if( head == NULL ) {
            return head;
        }
        
        ListNode *sortStart = head;
        ListNode *sortEnd   = head;
        
        if (sortEnd == NULL) {
            return head;
        }
        
        ListNode *curNode = sortEnd->next;
        
        while( curNode != NULL) {
            
            ListNode *curSort = sortStart;
            ListNode *preSort = sortStart;

            while (curSort != sortEnd) {
                if (curNode->val < curSort->val) { // less than
                    if (curSort == sortStart) {
                        sortEnd->next = curNode->next;
                        curNode->next = curSort;
                        sortStart = curNode;
                        break;
                    } else {
                        sortEnd->next = curNode->next;
                        preSort->next = curNode;
                        curNode->next = curSort;
                        break;
                    }
                } else { // great or equal than
                    preSort = curSort;
                    curSort = curSort->next;
                }
            }
            
            if (curSort == sortEnd) {
                if (curNode->val < curSort->val) {
                    sortEnd->next = curNode->next;
                    if (sortStart == sortEnd)
                        sortStart = curNode;
                    else
                        preSort->next = curNode;
                    
                    curNode->next = curSort;
                    
                } else {
                    sortEnd = curNode;
                }
            }
            
            curNode = sortEnd->next;
        }
        
        return sortStart;
    }
};

/*
 
 
 ListNode a(2);
 ListNode b(1);
 // ListNode c(3);
 
 a.next = &b;
 // b.next = &c;
 
 Solution s;
 ListNode * node = s.insertionSortList(&a);
 
 while ( node != NULL) {
 cout << " " << node->val;
 node = node->next;
 }
 cout << endl;
 
 
 */

#endif
