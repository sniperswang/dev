
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
	LinkedListNode a(0);
	LinkedListNode b(1);
	LinkedListNode c(1);
	LinkedListNode d(0);
	LinkedListNode e(1);
	LinkedListNode f(0);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	cout << getNumber(&a) << endl;
    return 0; 
}
