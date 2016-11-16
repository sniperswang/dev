
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

	void helper(vector< vector<int> >& res, TreeNode* root, int level)
	{	
		if (root == NULL)
		{
			return;
		}

		vector<int> vec;
		if ( level > res.size() )
		{
			vec.push_back(root->val);
			res.push_back(vec);
		}
		else 
		{
			res[level-1].push_back(root->val);
		} 

		if (root->left != NULL )
		{
			helper(res, root->left, level+1);
		}

		if (root->right != NULL)
		{
			helper(res, root->right, level+1);
		}
	}

    vector< vector<int> > levelOrderBottom(TreeNode* root) {
		vector< vector<int> > res;
		int level = 1;        
		helper(res, root, level);
		reverse(res.begin(), res.end());
		return res;
    }
};

  
int main() 
{
	TreeNode a(3);
	TreeNode b(9);
	TreeNode c(20);
	TreeNode d(15);
	TreeNode e(7);

	a.left  = &b;
	a.right = &c; 
	c.left  = &d;
	c.right = &e;

	Solution s;
	vector< vector<int> > res;
	res = s.levelOrderBottom(&a);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j =0; j < res[i].size(); j++)
		{
			cout << res[i][j] << ",";
		}
		cout << endl;
	}
    return 0;
}
