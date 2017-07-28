
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

	int binarySearch(vector<int>& numbers, int start, int end, int target)
	{
		if (start > end || end < 0 || start > (int)numbers.size()) 
		{
			
			return -1;
		}

		int index = (end + start ) / 2;
		if ( numbers[index] == target)
			return index;
		else if ( numbers[index] < target ) 
			return binarySearch(numbers, index + 1, end, target);
		else 
			return binarySearch(numbers, start, index - 1, target);
	
		return -1;
	}
	
    vector<int> twoSum(vector<int>& numbers, int target) {
    	vector<int> res;
		if (numbers.size() < 2 || numbers[0] > target)
		{
			return res;
		}
		
		int i = 0;
		while (numbers[i] <= target && i < numbers.size()) // " -1, 0 == -1" 
		{
			int j = binarySearch(numbers, i + 1, numbers.size()-1, target - numbers[i]);
			if (j != -1)
			{
				res.push_back(i);
				res.push_back(j);
				break;
			}
			i++;
		}
		return res; 
    }
};
  
int main() 
{
	vector<int> numbers;
	/*
	numbers.push_back(2);
	numbers.push_back(7);
	numbers.push_back(11);
	numbers.push_back(15);
	*/
	numbers.push_back(-1);
	numbers.push_back(0);
	Solution s;
	vector<int> res;
	res = s.twoSum(numbers, -1);
	if (res.size() == 2)
		cout << res[0] << ":" << res[1] << endl;
	else 
		cout << "null" << endl;
	//cout << s.binarySearch(numbers, 0, 1, 1) << endl;
		
    return 0;
}
