//
//  hasCycle.h
//  leetCode
//
//  Created by Yao Wang on 11/13/13.
//
//

#ifndef leetCode_hasCycle_h
#define leetCode_hasCycle_h


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        ListNode *oneStep = head;
        ListNode *twoStep = head;
        
        if(head == NULL) {
            return false;
        }
        
        if(head->next == NULL) {
            return false;
        }
        while(oneStep !=  NULL && twoStep != NULL ) {
            
            oneStep = oneStep->next;
            
            if(twoStep->next != NULL){
                twoStep = twoStep->next->next;
            }else{
                break;
            }
            
            if(oneStep == twoStep)
                return true;
            
        }
        
        return false;
    }
};


/*
 
 ListNode* a = new ListNode(1);
 ListNode* b = new ListNode(2);
 a->next = b;
 
 Solution s;
 
 cout << s.hasCycle(a) <<endl;
 
 */


#endif
