
#include <iostream>
#include <vector>
#include <map>
#include <algorithm> 

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int odd = 0;
		int even = 0;
		int len = nums.size();
		for ( int i = 0; i < len; i++ )
		{
			if (i % 2 == 0)
			{
				even += nums[i];
				even = max(odd,even);
			}
			else 
			{
				odd += nums[i];
				odd = max(odd, even);
			}
		}
		return max(odd,even);
	}
};

int main() 
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(8);
	nums.push_back(6);
	Solution s;
	cout << s.rob(nums) << endl;
    return 0;
}
