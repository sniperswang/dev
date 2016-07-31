
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class LinkedListNode
{
	public:
	int val;
	LinkedListNode *next;

	LinkedListNode(int node_value)
	{
		val = node_value;
		next = NULL;
	}
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, int val)
{
	if(head == NULL)
	{
		head = new LinkedListNode(val);
	}
	else 
	{
		LinkedListNode *end = head;
		while (end->next != NULL)
		{
			end = end->next;
		}
		LinkedListNode *node = new LinkedListNode(val);
		end->next = node;
	}
	return head;
}

LinkedListNode* MergeInBetween(LinkedListNode* L1, LinkedListNode* L2, int A, int B)
{
	LinkedListNode* headL1 = L1;
	LinkedListNode* nodeL1 = headL1;
	LinkedListNode* headL2 = L2;
	LinkedListNode* tailL2 = L2;

	LinkedListNode* nodeA_prev = NULL; 

	while (tailL2->next != NULL)
	{
		tailL2 = tailL2->next;	
	}

	nodeA_prev = nodeL1;
	nodeL1 = nodeL1->next;

	int i = 1;
	while(true)
	{
		if (A == 1)
		{
			headL1 = headL2;
			break;
		}
		if (i+1 == A)
		{
			nodeA_prev->next = headL2;
			break;
		}
		else 
		{
			nodeA_prev = nodeL1;
		}
		i++;
		nodeL1 = nodeL1->next;
	}
	while(true)
	{
		if ( B == 1)
		{
			tailL2->next = L1->next;
			break;
		}
		if (i+1 == B)
		{
			tailL2->next = nodeL1->next;
			break;
		}
		i++;
		nodeL1 = nodeL1->next;
	}

	return headL1;
}

void printL (LinkedListNode *L)
{   
	LinkedListNode* node = L;
	while(node != NULL)
	{
		cout << node->val << "->";
		node = node->next;
	}
	cout << endl;
} 

int main() 
{
	LinkedListNode a(1);
	LinkedListNode b(2);
	LinkedListNode c(3);
	LinkedListNode d(4);
	LinkedListNode e(5);
	LinkedListNode f(6);
	LinkedListNode g(7);
	LinkedListNode h(8);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	f.next = &g;
	g.next = &h;

	LinkedListNode* L = MergeInBetween(&a,&f,5,5);
	printL(L);
    return 0; 
}
