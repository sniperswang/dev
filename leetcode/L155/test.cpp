
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
	int val;
	Node* next;
	Node(int i)
	{
		val = i;
		next = NULL;
	}
};



class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minNode = NULL;
    }
    
    void push(int x) {
    	Node* node = new Node(x);
		if (minNode == NULL)
		{
			minNode = node;
		}
		else 
		{
			if (node->val <= minNode->val)
			{
				node->next = minNode;
				minNode = node;
			}
		}
		myVector.push_back(node);
    }
    
    void pop() {
    	if (myVector.size() != 0)
		{
			if ( myVector[myVector.size() - 1] == minNode ) 
			{
				minNode = minNode -> next;
			}
			delete myVector[myVector.size() - 1];
			myVector.pop_back();
		} 
    }
    
    int top() {
		if ( myVector.size() != 0 )
		{
			return myVector[myVector.size() - 1]->val;
		} 
		return 0;
    }
    
    int getMin() {
    	if (minNode != NULL)
			return minNode->val; 
		return 0;
    }

private:
	vector<Node*> myVector;
	Node* minNode;
};
  
int main() 
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl; //   --> Returns -3.
	minStack.pop();
	cout << minStack.top() << endl;    //  --> Returns 0.
	cout << minStack.getMin() << endl; //   --> Returns -2.

    return 0;
}
