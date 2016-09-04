
#include <iostream>
#include <vector>
#include <map>

using namespace std;
 
class Solution {
public:
	string convert(string s, int numRows) {
		string res;
		int len = s.size();
		if ( numRows == 1) 
		{
			return s;
		}
		for (int i = 0; i < numRows; i++)
		{
			int index = i;
			int j = 0;
			while(true)
			{
				if (index >= len )
				{
					break;
				}
				res += s[index];
				if ( i == numRows -1 || i == 0)
				{
					index = index + (numRows - 1) * 2;
				}
				else
				if (j % 2 == 0)
				{
					index = index + (numRows - i -1) * 2;
				}
				else 
				{
					index = index + ( i ) * 2;
				}
				j++;
			}
		}
		return res;
	}
};

int main() 
{
//	string str = "PAYPALISHIRING";
	string str = "ABCDEFGHIJKLMNOPQ";
	Solution s;
	cout << s.convert(str,5) << endl;
    return 0;
}
