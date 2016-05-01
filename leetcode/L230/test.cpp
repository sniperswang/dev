
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
	
	void treeHelper(TreeNode* root, int k, int& n, int& val) 
	{
		if (root->left == NULL && root->right == NULL ) 
		{
			n++;
			if ( n == k)
			{
				val = root->val;
			}
			return;
		}
		// count left;
		if (root->left != NULL)
		{
			treeHelper(root->left, k , n, val);
		}
		if( n == k) 
		{
			return;
		}
		// count current
		n++;
		if ( n == k)
		{
			val = root->val;
			return;
		}
		// count right
		if (root->right != NULL)
		{
			treeHelper(root->right, k , n, val);
		}
		if ( n == k)
		{
			return;
		}
		return;
	}
	int kthSmallest(TreeNode* root, int k) {
		int n = 0;
		int val = 0;
		treeHelper(root,k,n,val);
		return val;
	}
};

int main() 
{
	TreeNode a(1);
	TreeNode b(3);
	TreeNode c(4);
	TreeNode d(6);
	TreeNode e(7);
	TreeNode f(8);
	TreeNode g(10);
	TreeNode h(13);
	TreeNode i(14);

	f.left = &b;
	b.left = &a;
	b.right = &d;
	d.left = &c;
	d.right = &e;
	f.right = &g;
	g.right = &i;
	i.left = &h;

	Solution s;
	cout << s.kthSmallest(&f, 7) << endl;
    return 0;
}
