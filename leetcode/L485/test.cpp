
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
 			int max = 0;
			int sum = 0;

			for (int i = 0; i < nums.size();i++)
			{
				sum = (sum + nums[i]) * nums[i];
				max = (sum > max ) ? sum : max;
			} 
			return max;
    }
};
  
int main() 
{
    return 0;
}
