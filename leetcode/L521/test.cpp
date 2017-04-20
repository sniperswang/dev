
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	
	int helper(string& base, unordered_set<char>& smap, int maxLen)
	{	
		int currMax = 0;
		int currLen = 0;
		int i = 0;
		while(true)
		{
			if ( i < base.size() && smap.find(base[i]) == smap.end())
			{
				currLen++;
				if ( currMax < currLen )
				{
					currMax = currLen;
				}
				if ( currMax == maxLen)
					return maxLen;
			} 
			else if (i == base.size())
			{
				break;
			}
			else 
			{
				currLen = 0;
			}
			i++;
		}
		return currMax;
	}
	
    int findLUSlength(string a, string b) {
  		
		if (a.size() == 0 || b.size() == 0)      
		{
			return 0;
		}
		unordered_set<char> smap;
		if (a.size() > b.size())
		{
			for (int i = 0; i < b.size(); i++)
			{
				smap.insert(b[i]);
			}
			return helper(a, smap, b.size());
		}
		else 
		{
			for (int i = 0; i < a.size(); i++)
			{
				smap.insert(a[i]);
			}
			return helper(b, smap, a.size());
		}
		return 0;
    }
};
  
int main() 
{
	string a = "eeabaee";
	string b = "cdc";

	Solution s;
	cout << s.findLUSlength(a,b) << endl;
    return 0;
}
