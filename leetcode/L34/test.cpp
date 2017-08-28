
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
	
	int binaryUpperBoundSearch(vector<int>& numbers, int start, int end, int target)
    {
        if (start > end || end < 0 || start > (int)numbers.size())
        {

            return -1;
        }

        int index = (end + start ) / 2;
        if ( numbers[index] == target && ( (index == numbers.size() - 1) || numbers[index + 1] != target) )
            return index;
        else if ( numbers[index] <= target )
            return binaryUpperBoundSearch(numbers, index + 1, end, target);
        else
            return binaryUpperBoundSearch(numbers, start, index - 1, target);

        return -1;
    }

	int binaryLowerBoundSearch(vector<int>& numbers, int start, int end, int target)
    {
        if (start > end || end < 0 || start > (int)numbers.size())
        {

            return -1;
        }

        int index = (end + start ) / 2;
        if ( numbers[index] == target && ( (index == 0) || numbers[index - 1] != target) )
            return index;
        else if ( numbers[index] >= target )
            return binaryLowerBoundSearch(numbers, start, index - 1, target);
        else
            return binaryLowerBoundSearch(numbers, index + 1, end, target);

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
 		vector<int> res;
		return res;
    }
};
  
int main() 
{
	int  array[] = {5,7,7,8,8,10};
	vector<int> numbers(array, array + 6);

	Solution s;
	cout << s.binaryUpperBoundSearch(numbers, 0, numbers.size()-1, 9) << endl;
	cout << s.binaryLowerBoundSearch(numbers, 0, numbers.size()-1, 9) << endl;
    return 0;
}
