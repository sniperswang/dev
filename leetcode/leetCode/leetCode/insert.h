//
//  insert.h
//  leetCode
//
//  Created by Yao Wang on 2/19/14.
//
//

#ifndef leetCode_insert_h
#define leetCode_insert_h

//best

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        struct Val_lvl {
            int lvl;
            TreeNode *node;
            Val_lvl (TreeNode *n, int level): node(n), lvl(level) {}
        };
        
        vector< vector<int> > res;
        queue<Val_lvl> que;
        Val_lvl e(root,1);
        que.push(e);
        
        while(que.size() != 0) {
            Val_lvl top = que.front();
            
            TreeNode *local_root = top.node;
            if(local_root == NULL) {
                return res;
            }
            TreeNode *left  = top.node->left;
            TreeNode *right = top.node->right;
            if(left != NULL){
                Val_lvl child(left,top.lvl+1);
                que.push(child);
            }
            
            if(right != NULL){
                Val_lvl child(right,top.lvl+1);
                que.push(child);
            }
            
            if(res.size() < top.lvl) {
                vector<int> new_vec;
                new_vec.push_back(local_root->val);
                res.push_back(new_vec);
            } else {
                res[top.lvl-1].push_back(local_root->val);
            }
            
            que.pop();
            
        }
        
        return res;
    }
    
};


// better but time exceed

/*
 class Solution {
 public:
 vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
 // Start typing your C/C++ solution below
 // DO NOT write int main() function
 
 vector<Interval>::iterator it=intervals.begin();
 while(it!=intervals.end())
 {
 if(newInterval.end<it->start)
 {
 intervals.insert(it, newInterval);
 return intervals;
 }
 else if(newInterval.start>it->end)
 {
 it++;
 continue;
 }
 else
 {
 newInterval.start=std::min(newInterval.start, it->start);
 newInterval.end=std::max(newInterval.end, it->end);
 it=intervals.erase(it);
 }
 
 }
 
 intervals.insert(intervals.end(), newInterval);
 
 
 return intervals;
 
 }
 };
 */


/* all wrong
 struct Interval {
 int start;
 int end;
 Interval() : start(0), end(0) {}
 Interval(int s, int e) : start(s), end(e) {}
 };
 
 
 class Solution {
 public:
 vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
 vector<Interval> res;
 
 if (intervals.size() == 0) {
 res.push_back(newInterval);
 return res;
 }
 
 if (intervals.size() == 1) {
 vector<Interval>::iterator curr_iter = intervals.begin();
 
 if(newInterval.start > curr_iter->end) {
 res.push_back(*curr_iter);
 res.push_back(newInterval);
 return res;
 }
 
 if(newInterval.end < curr_iter->start) {
 res.push_back(newInterval);
 res.push_back(*curr_iter);
 return res;
 }
 
 if( newInterval.start > curr_iter->start) {
 newInterval.start = curr_iter->start;
 }
 
 if(newInterval.end < curr_iter->end) {
 newInterval.end = curr_iter->end;
 }
 
 res.push_back(newInterval);
 return res;
 }
 
 Interval merged_in;
 vector<Interval>::iterator curr_iter;
 vector<Interval>::iterator prev_iter = intervals.begin();
 
 if (newInterval.start < prev_iter->start ) {
 merged_in.start = newInterval.start;
 }
 
 if (newInterval.end < prev_iter->start ) {
 res.push_back (newInterval);
 res.push_back (*prev_iter);
 }
 
 for(curr_iter=intervals.begin() +1; curr_iter != intervals.end(); curr_iter++) {
 
 if (newInterval.start >curr_iter->start) {
 res.push_back(*prev_iter);
 }
 
 merged_in.start = curr_iter->start;
 
 if (newInterval.start >= prev_iter->start && newInterval.start < curr_iter->start) {
 
 if (newInterval.start <= prev_iter->end && newInterval.end > prev_iter->end ) {
 merged_in.start = prev_iter->start;
 } else {
 merged_in.start = newInterval.start;
 res.push_back(*prev_iter);
 }
 
 }
 
 if (newInterval.end >= prev_iter->end && newInterval.end < curr_iter->end) {
 
 if (newInterval.end  >= curr_iter->start ){
 merged_in.end = curr_iter->end;
 } else {
 merged_in.end = newInterval.end;
 
 }
 res.push_back(merged_in);
 }
 
 if (newInterval.end  < curr_iter->start){
 res.push_back(*curr_iter);
 }
 
 prev_iter = curr_iter;
 
 }
 
 if(newInterval.start > prev_iter->end) {
 res.push_back(*prev_iter);
 merged_in.start = newInterval.start;
 }
 
 if(newInterval.end > prev_iter->end) {
 merged_in.end = newInterval.end;
 res.push_back(merged_in);
 }
 
 
 
 return res;
 }
 };
 */

/*
 test
 


Interval a(0,2);
Interval b(3,9);

Interval in(6,8);


//   Interval in(4,9);

vector<Interval> intervals;
intervals.push_back(a);
intervals.push_back(b);
// intervals.push_back(c);
// intervals.push_back(d);
//  intervals.push_back(e);

Solution s;

vector<Interval> res = s.insert(intervals, in);

for( int i = 0; i < res.size(); i++) {
    cout << " <" << res[i].start << "," << res[i].end << ">";
    }
    cout << endl;
 
 */

#endif
