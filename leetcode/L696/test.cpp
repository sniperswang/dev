
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::min

using namespace std;


class Solution {
public:
    int countBinarySubstrings(string s) {

		if (s.size() == 0 || s.size() == 1)
			return 0;
		
      vector<int> group;

		int count = 1;

		for (int i = 1; i < s.size(); i++)
		{
			if (s[i-1] == s[i])
			{
				count++;
			}
			else 
			{
				group.push_back(count);
				count = 1;
			}
		}
		group.push_back(count);
	
		count = 0;
		for (int i = 1; i < group.size(); i++)
		{
			count += std::min(group[i-1], group[i]);
		}
		return count;
    }
};
  
int main() 
{
	//string ss = "00110011";
	string ss = "10101";
	Solution s;
	s.countBinarySubstrings(ss);
   return 0;
}
