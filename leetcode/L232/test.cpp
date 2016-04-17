
#include <iostream>
#include <vector>
#include <map>

using namespace std;
  
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
		   
class Solution {
	public:

	bool checkoutNode(TreeNode* left, TreeNode* right)
	{

		if( right == NULL && left != NULL) 
		{
			return false;
		}
		else if ( right != NULL && left == NULL)
		{
			return false;
		}
		else if ( right == NULL && left == NULL) 
		{
			return true;
		}

		if (left->val == right->val)
		{
			if (!checkoutNode(left->left, right->right))
			{
				return false;
			}
			if(!checkoutNode(left->right, right->left))
			{
				return false;
			}
		}
		else 
		{
			return false;
		}
		return true;
	}
	bool isSymmetric(TreeNode* root) {
		if ( root == NULL) 
			return true;

		TreeNode* left = root->left;
		TreeNode* right = root->right;
		return checkoutNode(left,right);
	}
};

int main() 
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(2);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(3);
	TreeNode g(4);
	TreeNode h(3);

	a.left  = &b;
	a.right = &c;
	b.left  = &d;
	b.right = &e;
	c.left  = &g;
	c.right = &f;
	f.right = &h;

	Solution s;
	cout << s.isSymmetric(&a) << endl;
    return 0;
}
