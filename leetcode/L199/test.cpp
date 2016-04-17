
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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> val;
		map<int,int> tmap;
		int level = 0;
		helper(tmap, root, level);

		map<int,int>::iterator iter;
		for ( iter = tmap.begin(); iter != tmap.end(); iter++)
		{
			val.push_back(iter->second);
		}

		return val;
	}

	void helper(map<int,int> &tmap, TreeNode* node, int level)
	{
		if (node != NULL)
		{
			tmap[level] = node->val;
			helper(tmap,node->left,level+1);
			helper(tmap,node->right,level+1);
		}
		return;
		
	}
};
		   
int main() 
{
	TreeNode a(0);
	TreeNode b(1);
	TreeNode c(2);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(5);
	TreeNode g(6);
	TreeNode h(7);
	TreeNode i(8);
	TreeNode j(9);
	TreeNode k(10);
	TreeNode l(11);
	TreeNode m(12);
	TreeNode n(13);
	TreeNode o(14);

	a.right = &b;
	b.left  = &c;
	b.right = &d;
	c.right = &e;
	e.left  = &g;
	e.right = &h;
	d.right = &f;
	f.right = &i;
	h.left  = &j;
	j.left  = &k;
	j.right = &l;
	l.left  = &m;
	l.right = &n; 

    Solution s;
	s.rightSideView(&a);

    return 0;
}
