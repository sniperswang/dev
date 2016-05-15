
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		int lenA = 0;
		int lenB = 0;

		ListNode* head = headA;
		while(head != NULL) 
		{
			lenA++;
			head = head->next;
		}
		
		head = headB;
		while(head != NULL)
		{
			lenB++;
			head = head->next;
		}

		ListNode* head_a = headA;
		ListNode* head_b = headB;

		if ( lenA > lenB )
		{
			int delta = lenA - lenB;
			while ( delta != 0 )
			{
				head_a = head_a->next;
				delta--;
			}
		}
		else 
		{
			int delta = lenB - lenA;
			while ( delta != 0 )
			{
				head_b = head_b->next;
				delta--;
			}
		}

		while(head_a != NULL )
		{
			if (head_a == head_b)
				return head_a;
			head_a = head_a->next;
			head_b = head_b->next;
		}

		return NULL;
	}
};
		   
int main() 
{
	ListNode a1(1);
	ListNode a2(2);
	ListNode b1(3);
	ListNode b2(4);
	ListNode b3(5);
	ListNode c1(6);
	ListNode c2(7);
	ListNode c3(8);

	a1.next = &a2;
	a2.next = &c1;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &c1;
	c1.next = &c2;
	c2.next = &c3;

	Solution s;
	ListNode* head = s.getIntersectionNode(&a1,&b1);

	if ( head != NULL )
	{
		cout << head->val << endl;
	}
    return 0;
}
