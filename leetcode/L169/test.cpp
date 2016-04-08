
#include <iostream>
#include <vector>
#include <map>

using namespace std;
				
class Solution {
	public:
	int majorityElement(vector<int>& nums) 
	{
		int len = nums.size();
		if ( len == 1 ) 
		{
			return nums[0];
		}

		int MAJOR_NUM = len / 2;
		for (int i = 0; i < len; i++)
		{
			if (numCounter.find(nums[i]) == numCounter.end())
			{
				numCounter[nums[i]] = 1;
			}
			else 
			{
				numCounter[nums[i]] ++; 
				if ( numCounter[nums[i]] > MAJOR_NUM ) 
				{
					return nums[i];
				}
			}
		}
		return 0;
	}
	map<int,int> numCounter;
};

int main() 
{
	// test case 
	vector<int> vec;
	vec.push_back(1);
	/*
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(7);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(7);
	vec.push_back(7);
	vec.push_back(7);
	vec.push_back(7);
	vec.push_back(7);
	vec.push_back(7);
	vec.push_back(7);
	vec.push_back(7);
	vec.push_back(1);
*/
	Solution s;
	cout << s.majorityElement(vec) << endl;
    return 0;
}
