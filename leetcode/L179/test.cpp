
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool myCmp(int a, int b) 
{

	int alen = 1;
	int blen = 1;
	int temp = a;

	while ( (temp = temp / 10) != 0 ) 
	{
		alen *= 10;
	}

	temp = b;

	while ( (temp = temp / 10) != 0 ) 
	{
		blen *= 10;
	}

	string x= to_string(a) + to_string(b);
	string y= to_string(b) + to_string(b);

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] > y[i])
			return true;
		if (x[i] < y[i])
			return false;
	}
	return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
		string res = "";
		sort(nums.begin(), nums.end(), myCmp); 
		for (int i = 0; i < nums.size(); i++)
		{
			res += to_string(nums[i]);
		}
		return res;       
    }
};

int main() 
{
	vector<int> nums;
	nums.push_back(999999998);
	nums.push_back(999999997);
	nums.push_back(999999999);
	/*
	nums.push_back(3544);
	nums.push_back(3013);
	nums.push_back(3061);
	nums.push_back(468);
	*/
	/*
	nums.push_back(3);
	nums.push_back(30);
	nums.push_back(34);
	nums.push_back(5);
	nums.push_back(9);
*/
	/*
	nums.push_back(1001);
	nums.push_back(1000);
	*/
	
	/*
	nums.push_back(12);
	nums.push_back(121);
	*/

	/*
	nums.push_back(3013);
	nums.push_back(3061);
	*/
	Solution s;
	cout << s.largestNumber(nums) << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ",";
	}
	cout << endl;
    return 0;
}
