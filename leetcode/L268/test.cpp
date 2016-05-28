
#include <iostream>
#include <vector>
#include <map>

using namespace std;
  

class Solution {
	public:
	int missingNumber(vector<int>& nums) {

		int len = nums.size();
		int res = 0;
		for (int i = 0; i < len; i ++)
		{
			res = res^i^nums[i];
		}
		res = res^len;
		return res;
	}
};


int main() 
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(3);
	Solution s;
	cout << s.missingNumber(nums) << endl;
    return 0;
}
