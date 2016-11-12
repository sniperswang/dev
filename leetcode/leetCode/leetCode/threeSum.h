//
//  threeSum.h
//  leetCode
//
//  Created by Yao Wang on 8/25/13.
//
//

#ifndef leetCode_threeSum_h
#define leetCode_threeSum_h

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        vector<int> array;
        vector<vector<int> > res;
        //set<vector<int>, myComparator> myset;
        if(num.size() < 3){
            return res;
        }
        
        
        for(int i = 0; i <= num.size()-3; i++) {
            int a = num[i];
            int k = i+1;
            int l = num.size() - 1;
            
            while(k < l) {
                int b = num[k];
                int c = num[l];
                int val = a+b+c ;
                if( val == 0){
                    array.push_back(a);
                    array.push_back(b);
                    array.push_back(c);
                    //  cout << a << " " << b << " " << c << endl;
                    res.push_back(array);
                    array.clear();
                    k++;
                    l--;
                    while(k<l && num[k] == num[k-1]) k++;
                    while(k<l && num[l] == num[l+1]) l--;
                    
                } else if (val > 0 ){
                    l--;
                } else if (val < 0) {
                    k++;
                }
                
            }
            
            if(i < num.size()- 1)
            {
                while(num[i] == num[i+1])
                    i++;
            }
        }
        return res;
    }
};

/*
 // int myints[] = {-1, 0, 1, 2, -1, -4};
 int myints[] = {0,0,0,0};
 std::vector<int> num (myints, myints + sizeof(myints) / sizeof(int) );
 Solution s;
 vector<vector<int> > res = s.threeSum(num);
 
 for(int i = 0; i < res.size(); i++ ){
 vector<int> array = res[i];
 for(int j = 0; j < array.size(); j++ ){
 cout << array[j] << " ";
 }
 cout << "\n";
 }
 */

#endif
