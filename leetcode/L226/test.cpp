
#include <iostream>
#include <vector>

using namespace std;
				
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	TreeNode* invertTree(TreeNode* root) {
		invertHelper(root);
		return root;
	}

	void invertHelper(TreeNode* root) 
	{
		if (root != NULL)
		{
			TreeNode* newleft  = root->right;
			TreeNode* newRight = root->left;
			invertHelper(root->left);
			invertHelper(root->right);
			root->left  = newleft;
			root->right = newRight; 
		}
		return;
	}
	void readNode(TreeNode* root)
	{
		if (root != NULL) 
		{
			readNode(root->left);
			cout<<root->val << " ";
			readNode(root->right);
		}
		return;
	}
};

int main() 
{
	// test case 
	TreeNode a(4);
	TreeNode b(2);
	TreeNode c(1);
	TreeNode d(3);
	TreeNode e(7);
	TreeNode f(6);
	TreeNode g(9);

	a.left  = &b;
	a.right = &e;
	b.left  = &c;
	b.right = &d;
	e.left  = &f;
	e.right = &g;

	Solution s;
	s.readNode(s.invertTree(&a));
	
    return 0;
}
