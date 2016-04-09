
#include <iostream>
#include <vector>
#include <map>

using namespace std;
  
class Solution {
	public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		if ( len == 1 || len == 0)
		{
			return;
		}
		
		int temp = 0;
		int steps = k % len;
		vector<int> store1;
		vector<int> store2;
		for( int i = 0; i < len-steps; i++) 
		{
			store1.push_back(nums[i]);
		}
		for( int i = 0; i < steps; i++)
		{
		 	store2.push_back(nums[len-i-1]);	
		}

		for( int i = 0; i < len-steps; i++)
		{
			nums[i+steps] = store1[i];
		}

		for( int i = 0; i < steps; i++)
		{
			nums[steps-i-1] = store2[i];
		}
	}
};

int main() 
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
//	nums.push_back(4);
//	nums.push_back(5);
//	nums.push_back(6);
//	nums.push_back(7);

	Solution s;
	s.rotate(nums,2);

	int len = nums.size();
	for ( int i =0; i < len; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
    return 0;
}
