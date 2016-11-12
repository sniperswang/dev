//
//  addListNum.h
//  leetCode
//
//  Created by Yao Wang on 7/10/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef leetCode_addListNum_h
#define leetCode_addListNum_h

/*
 
 Add Two Numbers
 
 You are given two linked lists representing two non-negative numbers. The res are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 
 */

/**
 * Definition for singly-linked list.
 
 */
/* example
 
 ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
 ListNode *s = new ListNode(0);
 ListNode *c = s;
 bool f1 = (NULL != l1);
 bool f2 = (NULL != l2);
 while(1) {
 if(f1) {
 c->val += l1->val;
 l1 = l1->next;
 f1 = (NULL != l1);
 }
 if(f2) {
 c->val += l2->val;
 l2 = l2->next;
 f2 = (NULL != l2);
 }
 bool carry = c->val / 10;
 c->val %= 10;
 if(f1 || f2 || carry) {
 c->next = new ListNode(carry);
 c = c->next;
 } else
 break;
 }
 return s;
 }
 
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_add_list {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode *res;
        ListNode *f1 = l1;
        ListNode *f2 = l2;
        ListNode *c=NULL;
        
        int carry = 0;
        while(true) {
            ListNode *temp = new ListNode(0);
            // empty list 
            if(f1 == NULL && f2 == NULL){
                res = new ListNode(0);
                res->next=NULL;
                return res;
            }
            if (f1 != NULL) {
                temp->val = f1->val;
                f1 = f1->next;
            }
            
            if(f2 != NULL) {
                temp->val += f2->val;
                f2 = f2->next;
            }
            
            int new_val   = (temp->val + carry) % 10;
            int new_carry = (temp->val + carry) / 10;
            temp->val = new_val;
            carry = new_carry;
            if(c == NULL){
                c=temp;
                res=temp;
            }else {
                c->next=temp;
                c=temp;
                c->next=NULL;
            }
            
            if(f1 == NULL && f2 == NULL) {
                if(carry !=0){
                    ListNode *end = new ListNode(carry);
                    end->next = NULL;
                    c->next = end;
                }
                break;
            }            
        }// while(true) 
        return res;        
    }// solution 
    
};





#endif
