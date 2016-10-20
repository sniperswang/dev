
#include <iostream>
#include <vector>
#include <map>

using namespace std;



class Solution {
public:

	string longestPalindrome(string s) 
	{
		int len = s.size();
		int p[len][len];

		memset(p, 0, sizeof(p));

		int maxL = 0, start = 0, end = 0;

		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < i; j++)
			{
				p[j][i] = ((s[j] == s[i]) && ((i - j < 2) || p[j+1][i-1]) );

				if ( p[j][i] && (i - j +1 ) > maxL)
				{
					maxL = i - j +1;
					start = j;
					end = i;
				}
			}
			p[i][i] = 1;
		}
		return s.substr(start, end-start + 1);
	}
};
  
int main() 
{
	//string str="ccd";
	string str="abcdefghiabbajhg";
	Solution s;
	cout << s.longestPalindrome(str) << endl;

    return 0;
}
