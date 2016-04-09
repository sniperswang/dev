
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
	int titleToNumber(string s) {
		int len = s.size();
		int val = 0;
		for ( int i = 0; i < len; i++ ) 
		{
			val = val*26 + int(s[i] - 'A' + 1)  ;
		}
		return val;
	}
};


int main() 
{
	string str = "AAA";

	Solution s;
	s.titleToNumber(str);
    return 0;
}
