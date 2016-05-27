
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
	public:

	void moveZeroes(vector<int>& nums) {
		int len = nums.size();
		if ( len == 0 || len == 1) 
		{
			return;
		}

		int pos = 0;
		for (int i = 0; i < len; i++ ) 
		{
			if ( nums[i] != 0)
			{
				if(pos < i )
				{
					nums[pos] = nums[i];
					nums[i] = 0;
				}
				pos++;
			}
		}
	}
};

int main() 
{
	vector<int> array;
	array.push_back(0);
	array.push_back(1);
	array.push_back(0);
	array.push_back(3);
	array.push_back(12);

	Solution s;
	s.moveZeroes(array);

	int len = array.size();
	for (int i =0; i < len; i++)
	{
		cout << array[i] << ",";
	}
	cout << endl;
    return 0;
}
