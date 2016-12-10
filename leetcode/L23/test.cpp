
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
	
	ListNode* mergeList(ListNode* node1, ListNode* node2)
	{
		if (node1 == NULL) return node2;
		if (node2 == NULL) return node1;
		ListNode head(-1);
		ListNode* p1;
		for(p1 = &head; (node1 != NULL && node2 != NULL); p1 = p1->next )
		{
			int val1 = node1->val;
			int val2 = node2->val;

			if ( val1 < val2 ) 
			{
				p1->next = node1;
				node1 = node1->next;
			}
			else 
			{
				p1->next = node2;
				node2 = node2->next;
			}
		}

		p1->next = (node1 == NULL) ? node2: node1;
		return head.next;
	}	

    ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];
		ListNode* p1 = lists[0];
		for (int i = 1; i < lists.size(); i++)
		{
			p1 = mergeList(p1, lists[i]);
		}
		return p1;
    }
};
  
int main() 
{
    return 0;
}
