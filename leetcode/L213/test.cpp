
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int odd = 0;
		int even = 0;
		int len = nums.size();

		if (len == 0)
		{
			return 0;
		}
		else if (len == 1)
		{
			return nums[0];
		}

		int maxhead = 0;
		for ( int i = 0; i < len -1; i++ )
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
		maxhead = max(odd,even);

		int maxtail = 0;
		odd = 0;
		even = 0;
		for ( int i = 1; i < len; i++ )
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
		maxtail = max(odd,even);
		return max(maxhead,maxtail);


	}
};



int main() 
{
    return 0;
}
