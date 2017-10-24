
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
 			int reminder = 0;
			int r = 0;
			string s = "";
			int len1 = num1.size()-1;
			int len2 = num2.size()-1;       

			while(len1 >= 0 || len2 >= 0)
			{
				int x = (len1 >= 0) ? num1[len1] - '0' : 0;
				int y = (len2 >= 0) ? num2[len2] - '0' : 0;

				r = (x + y + reminder) % 10;
				reminder = (x + y + reminder) / 10;

				s += char(r + '0');
				len1 --;
				len2 --;
			}
			if (reminder != 0)
				s += char(reminder + '0');
			std::reverse(s.begin(), s.end());
			return s;
    }
};
  
int main() 
{
	string s1 = "9899";
	string s2 = "99";

	Solution s;
	cout << s.addStrings(s1,s2) << endl;
    return 0;
}
