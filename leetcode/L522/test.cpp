
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


bool myCompare(const string& s1, const string& s2)
{	
	return s1.size() > s2.size();
} 

struct ByLength 
{
    bool operator()(const string& lhs, const string& rhs) const
    {
		if ( lhs == rhs )
		{
			return false;
		}

        return lhs.length() >= rhs.length();
    }
};

class Solution {
public:

	bool helper(const string& s1, const string& s2)
	{	
		int j = 0;
		for (int i = 0; i < s2.size(); i++)
		{
			if (s1[j] == s2[i])
				j++;

			if (j == s1.size())
				return false;
		}
		return true;
	}

    int findLUSlength(vector<string>& strs) {

		if (strs.size() == 1 || strs.size() == 0)
			return -1;
	
		map<string, int> myMap;

		for(int i = 0; i < strs.size(); i++)
		{
			myMap[strs[i]] ++;
		}

		std::sort(strs.begin(), strs.end(), myCompare);

		for (int i = 0; i < strs.size(); i++)
		{
			if ( myMap[strs[i]] > 1)
				continue;
			else 
			{
				if ( i == 0 )
					return strs[i].size();
				bool ret = true;
				for (int j = 0; j < i; j++)
				{
					if ( !helper( strs[i], strs[j]) )
					{
						ret = false;
						break;
					}
				}
				if (ret)
					return strs[i].size();
			}
		}

		return -1;
    }
};
  
int main() 
{
	vector <string> strs;

	
	
	/*
	strs.push_back("a");
	strs.push_back("b");
	strs.push_back("c");
	strs.push_back("d");
	strs.push_back("e");
	strs.push_back("f");
	strs.push_back("a");
	strs.push_back("b");
	strs.push_back("c");
	strs.push_back("d");
	strs.push_back("e");
	strs.push_back("f");
	*/
	Solution s;
	cout << s.findLUSlength(strs) << endl;

    return 0;
}
