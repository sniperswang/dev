//
//  levelOrder.h
//  leetCode
//
//  Created by Yao Wang on 9/29/13.
//
//

#ifndef leetCode_levelOrder_h
#define leetCode_levelOrder_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};






/*
 
 
 TreeNode a(1);
 TreeNode b(2);
 TreeNode c(3);
 TreeNode c_l(4);
 TreeNode c_r(5);
 
 a.right=&b;
 a.left=&c;
 c.right = &c_r;
 c.left  = &c_l;
 Solution s;
 
 vector < vector<int> > res;
 
 res = s.levelOrder(&a);
 
 for(int i = 0; i < res.size(); i++) {
 for( int j = 0; j < res[i].size(); j++) {
 cout << res[i][j] << " ";
 }
 
 cout<<endl;
 }
 
 */

#endif
