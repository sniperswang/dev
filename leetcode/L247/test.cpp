
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:


	void helper(vector <string> &res, vector<char> &e, string str, int pos, int n)
	{
		if ( (pos > n/2 && n % 2 != 0) || (pos >= n/2 && n % 2 ==0) )
		{
			res.push_back(str);
			return;
		}

		if ( (n == 1 && pos == 0 ) || ( n % 2 != 0 && (pos == n/2)))
		{
			for (int i = 0; i < e.size(); i++)
			{
				if (e[i] != '6' && e[i] != '9')
				{
					str[pos] = e[i];
					helper(res,e,str,pos+1,n);	
				}
			}	
		}
		else 
		{
			for (int i = 0; i < e.size(); i++)
			{
				str[pos] = e[i];
				if (e[i] == '6')
				{
					str[n-1-pos] = '9';
				}
				else if (e[i] == '9')
				{
					str[n-1-pos] = '6';
				}
				else 
				{
					str[n-1-pos] = e[i];
				}
				helper(res,e,str,pos+1,n);
			}
		}
		
		return;
	}
	

    vector<string> findStrobogrammatic(int n) {
        vector <string> res;
		if (n == 0)
			return res;
		vector<char> element;
		element.push_back('0');
		element.push_back('1');
		element.push_back('6');
		element.push_back('8');
		element.push_back('9');

		int hLen = int(n/2);
		
		string s(n,' ');

		if (n == 1)
			helper(res,element,s,0,n);
		else 
		{
			for (int i = 1; i < element.size(); i++)
			{
				s[0] = element[i];
				if (element[i] == '6')
				{
					s[n-1] = '9';
				}
				else if (element[i] == '9')
				{
					s[n-1] = '6';
				}
				else 
				{
					s[n-1] = element[i];
				}
				helper(res,element,s,1,n);
			}
		}
		
		return res;
		
    }
};
  
int main() 
{
	vector <string> res;
	Solution s;
	res = s.findStrobogrammatic(3);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}

    return 0;
}
