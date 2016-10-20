
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	public:
	int minCut(string s) 
	{
		int len = s.size();
		int d[len];
		bool p[len][len];

		for (int i = 0; i < len; i++)
		{
			d[i] = i;
		}

		for (int i =0; i < len; i++)
			for(int j =0; j < len; j++)
				p[i][j] = false;

		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j <= i; j++ )
			{
				if (s[i] == s[j] && ( (i-j < 2) || p[j+1][i-1])	)
				{
					p[j][i] = true;
					if ( j == 0)
					{
						d[i] = 0;
					}
					else
					{
						d[i] = min(d[i], d[j-1]+1);
					}
				}
			}
		}
		return d[len-1];
	}
};

int main() 
{
	//string str = "aab";
	string str = "cabababcbc";
	Solution s;
	cout << s.minCut(str) << endl;
    return 0;
}
