
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
		vector< vector<int> > res;
		if (nums.size () < 4)
		{
			return res;
		}

		sort(nums.begin(), nums.end());

		for (int i = 0; i <= nums.size() - 4; i++)
		{

			int a = nums[i];

			for ( int h = i + 1; h <= (nums.size() - 3); h++)
			{
				int k = h+1;
				int j = nums.size()-1;
				int b = nums[h];
				while ( k < j)
				{
					int c = nums[k];
					int d = nums[j];
					int val = a + b + c + d;
				//	cout << a << "," << b << "," << c << "," << d << endl;
					if ( val  == target)
					{
						vector <int> fit;
						fit.push_back(a);
						fit.push_back(b);
						fit.push_back(c);
						fit.push_back(d);
						res.push_back(fit);
						k ++;
						j --;
						while (  k < j && nums[k] == nums[k - 1] )
						{
							k++;
						}

						while ( k < j && nums[j] == nums[j+1])
						{
							j--;
						} 
					}
					else if ( val > target )
					{
						j -- ;
					} 
					else if (val < target )
					{
						k ++;
					}
				}

				while ( h < nums.size() - 3 && nums[h] == nums[h+1] )
				{
					h++;
				}
			}
			if(i < nums.size()- 1)
            {
                while(nums[i] == nums[i+1])
                    i++;
            }
		}
	
		return res;
    
    }
};

  
int main() 
{
	int array[] = {1, 0, -1, 0, -2, 2};

	vector <int> ss;
	ss.assign(array, array+6);

	Solution s;
	vector< vector<int> > res = s.fourSum(ss,0);

	for (int i = 0; i < res.size(); i++)
	{
		for(int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << ",";
		}
		cout << endl; 
	}
    return 0;
}
