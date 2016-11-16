
#include <iostream>
#include <vector>
#include <map>

using namespace std;


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
    ListNode *detectCycle(ListNode *head) {
 		ListNode *fast = head;
		ListNode *slow = head;

		while(fast != NULL && slow != NULL)
		{
			slow = slow->next;
			if (fast->next == NULL)
			{
				return NULL;
			}
			else 
			{
				fast = fast->next->next;
			} 

			if (slow == fast)
				break;
		}

		if (fast == NULL)
			return NULL;

		ListNode* start = head;
		while(start != slow)
		{
			start = start->next;
			slow = slow->next;
		}
		return start;
    }
};
  
int main() 
{
    return 0;
}
