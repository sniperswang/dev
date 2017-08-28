
#include <iostream>
#include <vector>
#include <map>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int preMax = nums[0];
        int preMin = nums[0];
        int maxSofar = preMax;

        for (int i = 1; i < nums.size(); i++)
        {
            int curMax = std::max(std::max(preMax*nums[i], nums[i]), preMin*nums[i]);
            int curMin = std::min(std::min(preMin*nums[i], nums[i]), preMax*nums[i]);
            preMax = curMax;
            preMin = curMin;

            maxSofar = std::max(maxSofar, curMax);
        }
    
        return maxSofar;
    }
};
  
int main() 
{
    return 0;
}
