
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		while(head != NULL && head->val == val)
		{
			head = head->next;
		}
		ListNode* node = head;
		ListNode* prev = head;
		while(node != NULL)
		{
			if (node->val == val)
			{
				prev->next = node->next;            
			}
			else
			{
				prev = node;
			}
			node = node->next;
		}
		return head;
	}
};
  
int main() 
{
    return 0;
}
