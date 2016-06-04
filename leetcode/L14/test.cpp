
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
	public:
	string longestCommonPrefix(vector<string>& strs) {
		string prefix ="";
		int len = strs.size();
		if(len == 0)
		{
			return prefix;
		}
		int strLen = strs[0].size();
		for (int i = 0; i < strLen; i++)
		{
			char commonLetter = strs[0][i];
			for(int j = 1; j< len; j++ )
			{
				if(strs[j][i] != commonLetter)
				{
					return prefix;
				}
			}
			prefix += commonLetter;
		}
		return prefix;
	}
};

int main() 
{
	string str1 = "Hello";
	string str2 = "Hell";
	string str3 = "Hel";

	vector<string> strs;
	strs.push_back(str1);
	strs.push_back(str2);
	strs.push_back(str3);

	Solution s;
	cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
