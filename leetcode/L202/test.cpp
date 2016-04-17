
#include <iostream>
#include <vector>
#include <map>

using namespace std;
  
class Solution {
public:
	bool isHappy(int n) {
		if (n == 0)
		{
			return false;
		}

		int sum = 0;
		int val = n;
		int div = 0;
		while ( (div = val / 10) != 0 ) 
		{

			int mod = val % 10;
			sum += mod * mod;
			val = val / 10;
		}
		sum += val*val;
		cout << "sum:"<<sum <<endl;
		if (sum == 1) 
		{
			return true;
		}
		else 
		{
			std::map<int,int>::iterator it;
			it = mymap.find(sum);
			if ( it != mymap.end())
			{
				if (it->second == 1)
				{
					return false;
				}
			}
			else 
			{
				mymap[sum] = 1;
				return isHappy(sum);
			}
		}

		return false;
	}
	map<int,int> mymap;
};

int main() 
{
	Solution s;
	cout << s.isHappy(13) << endl;
    return 0;
}
