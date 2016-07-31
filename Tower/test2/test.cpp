
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

LinkedListNode* optimal(LinkedListNode* L)
{
	if ( L == NULL)
	{
		return L;
	}
	vector<int> referMap(1000,0);
	LinkedListNode* node = L;
	LinkedListNode* prev = node;
	referMap[node->val]  = 1;
	node = node->next;
	while(node != NULL )
	{
		if ( referMap[node->val] == 0)
		{
			prev = node;
		}
		else 
		{
			prev->next = node->next;
		}
		referMap[node->val]  = 1;
		node = node ->next;
	}
	return L;
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



/*
 * Complete the function below.
  */
  /*
  For your reference:
  LinkedListNode
  {
	  int val;
		  LinkedListNode *next;
  };
  */
  long getNumber(LinkedListNode* binary)
  {
	LinkedListNode* head = binary;
	if (head == NULL)
	{
		return 0;
	}

	long number = head->val;
	head = head->next;

	while (head != NULL)
	{
		number <<= 1;
		if (head->val == 1)
		{
			number += 1 ;
		}
		head = head->next;
	}
	return number;
  }

int main() 
{
	LinkedListNode a(3);
	LinkedListNode b(4);
	LinkedListNode c(3);
	LinkedListNode d(2);
	LinkedListNode e(6);
	LinkedListNode f(1);
	LinkedListNode g(2);
	LinkedListNode h(6);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &h;
	
	LinkedListNode* head = optimal(&a);
	printL(head);
	//cout << getNumber(&a) << endl;
    return 0; 
}
