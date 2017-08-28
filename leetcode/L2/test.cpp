
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int fraction = 0;
        ListNode* head = NULL;
        ListNode* prev = NULL;
        
        while (l1 != NULL || l2 != NULL || fraction != 0)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum+= fraction;

            int reminder = sum % 10;
            fraction = sum / 10;

            if (head == NULL)
            {
                head = new ListNode(reminder);
                prev = head;
            }
            else 
            {
                prev->next = new ListNode(reminder);
                prev = prev->next;
            }

        }
        
        return head;

    }
};
  
int main() 
{
    return 0;
}
