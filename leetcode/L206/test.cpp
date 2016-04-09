
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
	ListNode* reverseList(ListNode* head) {

		ListNode* curr = head;
		ListNode *prev = NULL;;
		while( curr != NULL ) 
		{
		    head = curr;
			curr = curr->next;
			head->next = prev;
			prev = head;
		}
		return head;
	}
};

void traverse(ListNode* head) 
{
	while (head != NULL) 
	{
		cout<<head->val<<endl;
		head = head->next;
	}
}

int main() 
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);

	a.next = &b;
	b.next = &c;
	c.next = &d;

	Solution s;
	traverse(s.reverseList(&a));

    return 0;
}
