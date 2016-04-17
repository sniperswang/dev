
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>

using namespace std;


class Solution {
	public:
	int compareVersion(string version1, string version2) {

		vector<string> s1;
		vector<string> s2;

		s1 = split(version1,'.');
		s2 = split(version2,'.');

		int index = 0;
		int len_1 = s1.size();
		int len_2 = s2.size();
		while ( true ) 
		{
			if( index > len_1 && index > len_2 ) 
			{
				break;
			}
			int s1_int = (index < len_1)?  atoi(s1[index].c_str()):0;
			int s2_int = (index < len_2)?  atoi(s2[index].c_str()):0;
			
			int res = compareNumber(s1_int,s2_int);
			if ( res == 0 )
			{
				index ++;
				continue;
			}
			else 
			{
				return res;
			}
		}
		return 0;
	}

	int compareNumber(int a, int b)
	{
		if ( a > b)
		{
			return 1;
		}
		else if ( a < b)
		{
			return -1;
		}
		else 
		{
			return 0;
		}

	}

	vector<string> split(string str, char delimiter) {
		vector<string> internal;
		stringstream ss(str); // Turn the string into a stream.
		string tok;

		while(getline(ss, tok, delimiter)) {
			internal.push_back(tok);
		}

		return internal;
	}
};

int main() 
{
	Solution s;
	cout << s.compareVersion("1.0.0","1") << endl;
    return 0;
}
