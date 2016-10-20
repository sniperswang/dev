
#include <iostream>
#include <vector>
#include <map>

using namespace std;


using namespace std;

class LinkedListNode{
public:
	string val;
	LinkedListNode *next;

	LinkedListNode(string node_value) {
		val = node_value;
		next = NULL;
	}
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, string val){
	if(head == NULL) {
		head = new LinkedListNode(val);
	}
	else {
		LinkedListNode *end = head;
		while (end->next != NULL) {
			end = end->next;
		}

		LinkedListNode *node = new LinkedListNode(val);
		end->next = node;
	}
	return head;
}

bool isInCitisToSkip(string& val, vector <string>& citiesToSkip)
{
	int len = citiesToSkip.size();
	for (int i = 0; i < len; i++)
	{
		cout << val << ":" << citiesToSkip[i] << endl;
		if (val.compare(citiesToSkip[i]) == 0)
		{
			cout << "0" << endl;
			return true;
		}
		cout << "!0" << endl;
	}
	return false;
}

LinkedListNode* updateRoute(LinkedListNode* initialRoute, vector < string > citiesToSkip) {
	LinkedListNode *head = initialRoute;
	LinkedListNode *node = head;
	LinkedListNode *prev = NULL;
	if (head == NULL)
	{
		return initialRoute;
	}

	while(node != NULL)
	{
		if (isInCitisToSkip(node->val, citiesToSkip) )
		{
			if (prev == NULL)
			{
				head = node->next;
			}
			else 
			{
				prev->next = node->next;

			}
			node = node->next;
			continue;
		}
		prev = node;
		node = node->next;
	}
	return head;

}
  
int main() 
{
 	LinkedListNode* head = NULL;
	head = _insert_node_into_singlylinkedlist(head, "Seattle");
	head = _insert_node_into_singlylinkedlist(head, "Tacoma");
	head = _insert_node_into_singlylinkedlist(head, "Portland");
	head = _insert_node_into_singlylinkedlist(head, "Los Angeles");
	head = _insert_node_into_singlylinkedlist(head, "Austin");
	head = _insert_node_into_singlylinkedlist(head, "Dallas");
	/*
	head = _insert_node_into_singlylinkedlist(head, "bb");
	head = _insert_node_into_singlylinkedlist(head, "cc");
	head = _insert_node_into_singlylinkedlist(head, "ee");
	*/
	vector < string > citiesToSkip;
	citiesToSkip.push_back("Seattle");
	citiesToSkip.push_back("Portland");
	citiesToSkip.push_back("Los Angeles");

	head = updateRoute(head, citiesToSkip);

	LinkedListNode* node = head;
	while (node != NULL)
	{
		cout << node->val << "->";
		node = node->next;
	}
	cout << endl;
    return 0;
}
