
#include <iostream>
#include <vector>
#include <map>

using namespace std;
  
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printNode(ListNode* head) 
{
	while (head != NULL)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << endl;
}

class Solution {
public:

	bool reverseAble(ListNode* head, int k)
	{	
		int i = 0;
		while(head != NULL)
		{
			head = head->next;
			i++;
			if(i == k)
				return true;
		}
		return false;
	}

	ListNode* reverse(ListNode* head, int k)
	{
		ListNode* start = head;
		ListNode* prev = NULL;
		ListNode* curr = start;
		ListNode* next = start->next;
		int i = 1;
		while (i < k )
		{
			prev = curr;
			curr = next;
			next = curr->next;
			curr->next = prev;
			i++;
		}
		head->next = next;
		cout << "curr:" << curr->val << endl;
		return  curr; 
	}
		
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 0 || k == 1)
			return head;

		ListNode* node = head;
		ListNode* next = head;
		ListNode* prev = head;
		int i = 0;
		while( reverseAble(next,k) ) 
		{
			printNode(head);
			printNode(next);
			if (i == 0 )
			{
				node = reverse(next,k);	
				head = node;
				cout << "head:" << head->val << endl;
			}
			else 
			{
				node = reverse(next,k);
			}
			if ( i != 0 )
				prev->next = node;
			prev = next;
			next = next->next;
			cout << "next:" << next->val << endl;
			i++;
		}
		cout << "end:" << endl;
		printNode(head);
		return head;
    }
};



int main() 
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	ListNode g(7);
	
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;

	Solution s;
	ListNode* head = &a;
	s.reverseKGroup(head,3);

	//printNode(head);

    return 0;
}
