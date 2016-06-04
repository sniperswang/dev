
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
	public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> mySet;
		int len = nums.size();
		if (len == 0 || len == 1)
			return false;

		for (int i =0; i < len; i++)
		{
			if (mySet.find(nums[i]) != mySet.end())
			{
				return true;
			}
			else
			{
				mySet.insert(nums[i]);
			}
		}
		return false;
	}
};


int main() 
{
    return 0;
}
