
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort

using namespace std;

bool myfunction (vector<int>& i, vector<int>& j) 
{ 
	return (i[0] < j[0] );
}

struct Solution
{

	int findMax(vector< vector<int> >& input )
	{
		sort(input.begin(),input.end(), myfunction);

		int ending = 0; 
		int ans = 0;

		for (int i = 0; i < input.size(); i++)
		{
			ans += max(input[i][1] - max(input[i][0], ending), 0);
			ending = max(input[i][0], ending);
		}

		return ans;
	}
};
  
int main() 
{
	vector<int> v;
	vector< vector<int> > input;
	int a[] = {1,4};
	v.assign(a,a+2);	
	input.push_back(v);
	v.clear();
	v.push_back(6);
	v.push_back(8);
	input.push_back(v);
	v.clear();
	v.push_back(2);
	v.push_back(4);
	input.push_back(v);
	v.clear();
	v.push_back(7);
	v.push_back(9);
	input.push_back(v);
	v.push_back(10);
	v.push_back(15);
	input.push_back(v);
	Solution s;
	cout << s.findMax(input) << endl;

    return 0;
}
