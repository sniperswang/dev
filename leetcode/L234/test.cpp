
#include <iostream>
#include <vector>
#include <map>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL)
		{
			return true;
		}

		ListNode* midNode = head;
		ListNode* firstHalfStartPoint = NULL; 
		ListNode* secondHalfStartPoint = NULL;
		ListNode* jumpNode = head;
		ListNode* prev = head;
		ListNode* next = head->next;


		while(true)
		{
			jumpNode = jumpNode->next;
			if (jumpNode == NULL)
			{
				firstHalfStartPoint = midNode->next; 
				secondHalfStartPoint = next;
				break;
			}
			else
			{
				jumpNode = jumpNode->next;
				midNode = next;
				if ( next != NULL )
					next = next->next;
				midNode->next = prev;
				prev = midNode;
			}

			if (jumpNode == NULL)
			{
				firstHalfStartPoint = midNode->next;
				midNode->next = next;
				secondHalfStartPoint = midNode;
				break;
			}
		}
		head->next = NULL;

		while( firstHalfStartPoint != NULL ) 
		{
			if( firstHalfStartPoint->val != secondHalfStartPoint->val)
			{
				return false;
			}
			else 
			{
				firstHalfStartPoint = firstHalfStartPoint->next;
				secondHalfStartPoint = secondHalfStartPoint->next;
			}
		}

		return true;
	}
};

int main() 
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
//	ListNode cc(4);
	ListNode d(4);
	ListNode e(3);
	ListNode f(2);
	ListNode g(1);

	a.next = &b;
	b.next = &c;
	c.next = &d;
//	c.next = &cc;
//	cc.next =&d;
	d.next = &e;
	e.next = &f;
	f.next = &g;

	Solution s;
	
	cout << s.isPalindrome(NULL) << endl;
    return 0;
}
