
#include <iostream>
#include <vector>
#include <map>

using namespace std;



class Solution {
	public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int len = nums.size();
		map<int,int> mymap;
		for (int i = 0; i < len; i++)
		{
			if (mymap.find(nums[i]) == mymap.end())
			{
				mymap[nums[i]] = i;
			}
			else 
			{
				if(i - mymap[nums[i]] < k)
					return true;
				else
					mymap[nums[i]] = i;		
			}
		}

		return false;
	}
};


int main() 
{
    return 0;
}
