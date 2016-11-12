
#include <iostream>
#include <vector>
#include <map>

using namespace std;


/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> genBST(int min, int max)
    {
        vector<TreeNode*> res;

        if (min > max)
        {
            res.push_back(NULL);
            return res;
        }

        for (int i = min; i <= max; i++)
        {
            vector<TreeNode *> leftTree = genBST(min, i-1);
            vector<TreeNode *> rightTree = genBST(i+1, max);

            for (int j = 0; j < leftTree.size(); j++)
                for (int k = 0; k < rightTree.size(); k++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    res.push_back(root);
                }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if ( n == 0)
        {
            return ret;
        }
        return genBST(1,n);
    }
};
  
int main() 
{
	vector<TreeNode*> res;
	Solution s;
	res = s.generateTrees(3);
    return 0;
}
