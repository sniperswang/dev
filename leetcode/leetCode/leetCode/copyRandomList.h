//
//  copyRandomList.h
//  leetCode
//
//  Created by Yao Wang on 1/18/14.
//
//

#ifndef leetCode_copyRandomList_h
#define leetCode_copyRandomList_h

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        map<RandomListNode*, RandomListNode*> map_RO_RN;
        
        RandomListNode* new_head = NULL;
        
        if (head == NULL) {
            return new_head;
        } else {
            new_head = new RandomListNode(head->label);
            map_RO_RN [head] = new_head;
        }
        
        RandomListNode* curr  = head->next;
        
        while (curr != NULL) {
            RandomListNode* new_curr = new RandomListNode (curr->label);
            map_RO_RN [curr] = new_curr;
            curr = curr->next;
        }
        
        curr = head;
        
        while (curr != NULL) {
            RandomListNode* new_curr = map_RO_RN [curr];
            if (curr->next != NULL) {
                RandomListNode* new_next = map_RO_RN[curr->next];
                new_curr->next = new_next;
            }
            
            if (curr->random != NULL) {
                RandomListNode* new_random = map_RO_RN[curr->random];
                new_curr->random = new_random;
            }
            
            curr = curr->next;
        }
        
        return new_head;
    }
};


#endif
