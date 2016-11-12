//
//  maxArea.h
//  leetCode
//
//  Created by Yao Wang on 3/12/14.
//
//

#ifndef leetCode_maxArea_h
#define leetCode_maxArea_h


/*
 
 Container With Most Water
 
 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 
 Note: You may not slant the container.
 */

class Solution {
public:
    int maxArea(vector<int> &height) {
        
        map<int, unsigned long long > mHStart;
        map<int, unsigned long long > mHEnd;
        
        const unsigned long long len = height.size();
        
        if (len == 0) {
            return 0;
        }
        
        if(len == 1) {
            return height[0];
        }
        
        int i = 0;
        int j = len - 1;
        
        int maxVal=0;
        while(i < j) {
            int local_max = 0;
            if(height[i] < height[j]) {
                local_max = height[i] * (j - i);
                i++;
            } else {
                local_max = height[j] * (j - i);
                j--;
            }
            
            if(maxVal < local_max)
                maxVal = local_max;
        }
        
        return maxVal;
        
    }
};

/*
 //int i_hight[] = {2,3,3,2,7,7};
 int i_hight[] = {2,1};
 vector<int> height;
 height.assign(i_hight, i_hight+2);
 
 Solution s;
 int res = s.maxArea(height);
 
 cout << "max:" <<res <<endl;
 
 */
#endif
