
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>   

using namespace std;


class Solution {
	public:
	int findDuplicate(vector<int>& nums) {
		int len = nums.size();
		int res = 0;
		
		sort(nums.begin(),nums.end());
		for(int i = 0; i < len -1; i++)
		{
			if ( nums[i] == nums[i+1] ) 
			{
				return nums[i];
			}
		}
		return res;
	}
};

int main() 
{
	vector<int> nums;
	/*
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(10);
	nums.push_back(11);
*/
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(3);
	Solution s;
	cout << s.findDuplicate(nums) << endl;
    return 0;
}
