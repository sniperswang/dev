
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int len = nums.size();
		int subLen = 0;
		int minLen = 0;
		for ( int i = 0; i < len; i++)
		{
			subLen = 1;
			int sum = nums[i];
			for ( int j = i+1; j < len; j++) 
			{
				if ( sum >= s)
				{
					break;
				}
				sum += nums[j];
				subLen ++;
			}

			if ( sum < s)
			{
				continue;
			}
			else if ( minLen == 0 )
			{
				minLen = subLen;
			}

			if ( subLen < minLen)
			{
				minLen = subLen;
			}
		}
		return minLen;
	}
};


int main() 
{
	vector<int> exp;
	exp.push_back(2);
	exp.push_back(3);
	exp.push_back(1);
	exp.push_back(2);
	exp.push_back(4);
	exp.push_back(3);
	/*
	exp.push_back(3);
	exp.push_back(3);
	exp.push_back(1);
	exp.push_back(1);
	exp.push_back(1);
	exp.push_back(1);
	exp.push_back(4);
	*/

	Solution s;
	cout << s.minSubArrayLen(7,exp) << endl;

    return 0;
}
