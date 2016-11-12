//
//  rotateRight.h
//  leetCode
//
//  Created by Yao Wang on 11/5/13.
//
//

#ifndef leetCode_rotateRight_h
#define leetCode_rotateRight_h

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL)
            return head;
        ListNode *node =head;
        ListNode *LastNode =head;
        int len = 0;
        while(node != NULL) {
            LastNode = node;
            node = node->next;
            len ++;
        }
        
        int real_k = k % len;
        
        if(real_k == 0)
            return head;
        int i = 0;
        ListNode *preNode = head;
        while( i < real_k-1) {
            preNode = preNode->next;
            i++;
        }
        
        ListNode *currNode = head;
        ListNode *oldNode  = head;
        ListNode *prePretNode = head;
        while(preNode != NULL){
            prePretNode = oldNode;
            oldNode = currNode;
            currNode = currNode->next;
            preNode = preNode->next;
        }
        
        LastNode->next = head;
        head = oldNode;
        prePretNode ->next = NULL;
        return head;
    }
};

#endif
