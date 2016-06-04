#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
 
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	void helper(TreeNode* root,vector<string> &strs, string str)
	{
		if (root == NULL)
		{
			return;
		}
//		cout << root->val << endl;
		if(root->left == NULL && root->right == NULL)
		{
			if (str.size() == 0)
			{
				str = to_string(root->val);
			}
			else
			{
				str = str + "->"+to_string(root->val);
			}
//			cout << str << endl;
			strs.push_back(str);
			return;
		}
	
		if (str.size() == 0)
		{
			helper(root->left,strs,to_string(root->val));
			helper(root->right,strs,to_string(root->val));
		}
		else 
		{
			helper(root->left,strs,str+"->"+to_string(root->val));
			helper(root->right,strs,str+"->"+to_string(root->val));
		}
		return;
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> strs;
		if(root != NULL)
		{
			helper(root,strs,"");

		}
		return strs;

	}
};
		    


int main() 
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode e(5);

	a.left = &b;
	a.right = &c;
	b.right = &e;

	Solution s;
	vector<string> strs = s.binaryTreePaths(&a);

	for (int i = 0; i< strs.size(); i++)
	{
		cout << strs[i] << endl;
	}
	
    return 0;
}
