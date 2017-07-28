
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

	
	int aDigit = a / alen;
	int bDigit = b / blen;
	alen /= 10;
	blen /= 10;

	while( alen != 0 || blen != 0 ) 
	{
		cout << "a:" << aDigit << endl;
		cout << "b:" << bDigit << endl;
		if ( aDigit < bDigit ) 
			return false;

		else if ( aDigit > bDigit ) 
			return true;

		if (alen != 0 )
		{
			if ( aDigit != 0 )
			{
				a = a % ( aDigit * alen *10);
				cout << "a1:" << a << endl;
			}
			else 
				a = 0;
			aDigit = a / alen;
			alen /= 10;
			
		}

		if( blen != 0 )
		{
			if ( bDigit != 0 )
			{
				b = b % ( bDigit * blen *10);
				cout << "b1:" << b << endl;
				
			}
			else 
				b = 0;
			bDigit = b / blen; 
			blen /= 10;
		}
		
	}
	return aDigit > bDigit;
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

	nums.push_back(3013);
	nums.push_back(3061);

	Solution s;
	cout << s.largestNumber(nums) << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ",";
	}
	cout << endl;
    return 0;
}
