//
//  nextPermutation.h
//  leetCode
//
//  Created by Yao Wang on 9/28/13.
//
//

#ifndef leetCode_nextPermutation_h
#define leetCode_nextPermutation_h

class Solution { //my way
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int>::iterator iter;
        vector<int>::iterator currPreIter;
        int len = 1;
        for(iter = num.end() -1;iter >= num.begin() + 1; iter--) {
            currPreIter = iter -1;
            if(*currPreIter >= *iter) {
                len ++;
            } else {
                break;
            }
        }
        
        std::sort(iter, iter+len);
        
        if (iter != num.begin()) {
            vector<int>::iterator preIter = iter-1;
            for(vector<int>::iterator curr_iter = iter; curr_iter<=iter+len; curr_iter++) {
                if(*curr_iter > *preIter) {
                    swap(*curr_iter, *preIter);
                    break;
                }
            }
        }
        
    }
};

class Solution { // STL way
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(next_permutation(num.begin(), num.end()) ) {
            return;
        } else {
            sort(num.begin(),num.end());
        }
    }
};

/*
 int myints  [] = {2,3,5,4,2};
 std::vector<int> num (myints, myints + sizeof(myints) / sizeof(int) );
 Solution s;
 s.nextPermutation(num);
 
 for(int i = 0; i < num.size(); i++) {
 cout << num[i] << " ";
 }
 
 cout << endl;

 
 */


#endif
