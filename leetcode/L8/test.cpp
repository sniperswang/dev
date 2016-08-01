
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	public:
	int myAtoi(string str) {
		long long res = 0;
		int index = 0;
		int sign = 1;
		int len = str.size();
		while (str[index] == ' '&& index < len)
		{
			index++;
		}

		if(str[index] == '-' && index < len)
		{
			sign = -1;
			index++;
		}
		else if(str[index] == '+' && index < len)
		{
			index++;
		}

		while (index < len)
		{
			if ( str[index] <= '9' && str[index] >= '0' )
			{
				res = res*10 + str[index] - '0';
			}
			else 
			{
				break;
			}

			if(res > (unsigned long long)INT_MAX )
			{
				return  sign == -1 ? INT_MIN : INT_MAX;
			}
			index++;
		}

		return int(res*sign);
	}
};


int main() 
{
	string str = "    10522545459";
	Solution s;
	cout << "orig:" << atoi(str.c_str()) << endl;
	cout << "test:" << s.myAtoi(str) << endl;
	//s.myAtoi(str);
    return 0;
}
