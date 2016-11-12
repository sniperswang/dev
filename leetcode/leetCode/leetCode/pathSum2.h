//
//  pathSum2.h
//  leetCode
//
//  Created by Yao Wang on 9/23/13.
//
//

#ifndef leetCode_pathSum2_h
#define leetCode_pathSum2_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector< vector<int> > vvec;
        
        if (root == NULL) {
            return vvec;
        }
        
        vector<int> v;
        if(root->left == NULL && root->right == NULL) {
            if( root->val == sum){
                v.push_back(root->val);
                vvec.push_back(v);
                return vvec;
            }else{
                return vvec;
            }
        }
        
        helper(root,sum,0,v,vvec);
        return vvec;
        
    }
    
    void helper(TreeNode *root, int& sum, int currSum, vector<int> & currVec, vector< vector<int>  > &totalVec ){
        if(root->left == NULL && root->right == NULL) {
            if( (currSum + root->val) == sum){
                currVec.push_back(root->val);
                totalVec.push_back(currVec);
                currVec.pop_back();
                return;
            }else{
                return;
            }
        }
        
        if(root->right != NULL) {
            currVec.push_back(root->val);
            helper(root->right, sum, currSum+root->val, currVec, totalVec);
            currVec.pop_back();
        }
        
        if(root->left != NULL) {
            currVec.push_back(root->val);
            helper(root->left, sum, currSum+root->val, currVec, totalVec);
            currVec.pop_back();
        }
        
    }
};

/*

 TreeNode a(1);
 TreeNode b(2);
 
 a.right=&b;
 
 Solution s;
 vector<vector<int> > vvec;
 vvec = s.pathSum(&a,3);
 
 for(int i = 0; i < vvec.size(); i++){
 for(int j = 0; j < vvec[i].size(); j++) {
 cout << vvec[i][j] << " ";
 }
 cout << endl;
 }
 
 cout << "hello" <<endl;
 
 */


#endif
