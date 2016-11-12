//
//  reverseList.h
//  leetCode
//
//  Created by Yao Wang on 7/21/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef leetCode_reverseList_h
#define leetCode_reverseList_h

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_reverse_list {
public:
    ListNode* reverseList(ListNode *l1) {
        ListNode *head = NULL;
        ListNode *curr = l1;
        ListNode *prev = NULL;
        
        while(curr != NULL) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev=curr;
            curr = next;
            
        }
        
        head = prev;
        return head;
    }
    
    void printList(ListNode* l1) {
        ListNode * curr = l1;
        
        while(curr != NULL){
            cout<<curr->val<<"\n";
            curr = curr->next;
        }
    }
};


#endif
